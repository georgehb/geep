#include "geep.h"
#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/kd.h>
#include <math.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>


static uint64_t min(uint64_t x, uint64_t y)
{
	return x < y ? x : y;
}

static uint64_t time_diff(const struct timespec *cur,
		const struct timespec *old);
static void do_beep(int freq, int console_fd);

static int console_fd = -1;
static int quality;
static uint64_t tot_length;

int geep_setup(int sound_quality)
{
	quality = sound_quality;
	tot_length = 0;
	if ((console_fd = open("/dev/tty0", O_WRONLY | O_CLOEXEC)) == -1) {
		console_fd = open("/dev/vc/0", O_WRONLY | O_CLOEXEC);
	}
	if (console_fd == -1) {
		perror("Couldn't open /dev/tty0 or /dev/vc/0");
		exit(EXIT_FAILURE);
	}
	return console_fd;
}

void geep_close()
{
	close(console_fd);
}

void beep(uint64_t length, int num_notes, ...) {
	static struct timespec start = { 0, 0 };
	struct timespec time;
	uint64_t diff;
	va_list arg_ptr;
	int periods[num_notes];
	static uint64_t sample = 0;
	int samples[num_notes];
	uint64_t next_tick;
	uint64_t overshoot = 0;

	va_start(arg_ptr, num_notes);
	for (int i = 0; i < num_notes; i++) {
		periods[i] = CLOCK_TICK_RATE / va_arg(arg_ptr, int);
		samples[i] = sample / periods[i] + 1;
	}
	va_end(arg_ptr);

	if (start.tv_sec == 0 && start.tv_nsec == 0) {
		clock_gettime(CLOCK_REALTIME, &start);
	}
	clock_gettime(CLOCK_REALTIME, &time);
	diff  = time_diff(&time, &start) * CLOCK_TICK_RATE / 1000000000;
	tot_length += length;

	while (diff < tot_length * CLOCK_TICK_RATE / 1000000000) {
		next_tick = UINT64_MAX;
		for (int i = 0; i < num_notes; i++) {
			while (sample > periods[i] * samples[i]) {
				samples[i]++;
			}
			next_tick = min(next_tick, periods[i] * samples[i]);
		}
		for (int i = 0; i < num_notes; i++) {
			if (next_tick == periods[i] * samples[i]) {
				samples[i]++;
			}
		}
		/* 
		 * The following two magic numbers are just that - they sound
		 * good on George's machine, who knows why.
		 */
		ioctl(console_fd, KIOCSOUND, 40000);
		while (diff < sample + quality) {
			clock_gettime(CLOCK_REALTIME, &time);
			diff = time_diff(&time, &start) * CLOCK_TICK_RATE / 1000000000;
		}
		ioctl(console_fd, KIOCSOUND, 0);
		while (diff < next_tick && diff < tot_length * CLOCK_TICK_RATE / 1000000000) {
			clock_gettime(CLOCK_REALTIME, &time);
			diff = time_diff(&time, &start) * CLOCK_TICK_RATE / 1000000000;
		}
		overshoot = diff - next_tick;
		sample = next_tick + overshoot;
	}
}

void rest(uint64_t length)
{
	struct timespec start;
	struct timespec time;
	struct timespec sleep = {0, 1000000};
	uint64_t diff;
	
	clock_gettime(CLOCK_REALTIME, &start);
	clock_gettime(CLOCK_REALTIME, &time);
	diff  = time_diff(&time, &start);
	tot_length += length;

	while (diff < length) {
		nanosleep(&sleep, NULL);
		clock_gettime(CLOCK_REALTIME, &time);
		diff  = time_diff(&time, &start);
	}
}

uint64_t time_diff(const struct timespec * const cur,
		const struct timespec * const old)
{
	uint64_t sec = (uint64_t)(cur->tv_sec - old->tv_sec);
	uint64_t nsec;
	if (sec == 0) {
		nsec = (uint64_t)(cur->tv_nsec - old->tv_nsec);
		return nsec;
	}
	nsec = 1000000000 * sec;
	if (old->tv_nsec > cur->tv_nsec) {
		nsec -= (uint64_t)(old->tv_nsec - cur->tv_nsec);
	} else {
		nsec += (uint64_t)(cur->tv_nsec - old->tv_nsec);
	}
	return nsec;
}

void do_beep(int freq, int console_fd)
{
	int period = (freq != 0 ? (int)(CLOCK_TICK_RATE/freq) : freq);
	ioctl(console_fd, KIOCSOUND, period);
}

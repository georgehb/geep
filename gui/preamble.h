#ifndef PREAMBLE_H
#define PREAMBLE_H

char preamble[] = 
"#include \"notes.h\"\n"
"#include \"../geep.h\"\n"
"#include <linux/kd.h>\n"
"#include <signal.h>\n"
"#include <stdio.h>\n"
"#include <stdlib.h>\n"
"#include <sys/ioctl.h>\n"

"static int console_fd = -1;\n"

"void quit(int sig)\n"
"{\n"
"	ioctl(console_fd, KIOCSOUND, 0);\n"
"	exit(EXIT_FAILURE);\n"
"}\n"

"int main()\n"
"{\n"
"	console_fd = geep_setup(100);\n"
"	signal(SIGINT, quit);\n";

char end_string[] =
"	geep_close();\n"
"	exit(EXIT_SUCCESS);\n"
"}\n";
#endif /* PREAMBLE_H */

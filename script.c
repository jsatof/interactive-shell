#include <stdio.h>
#include <stdlib.h>

// this creates a shell script, allowing for running in a linux envorinment
// everything in-between the first set of quotations will be executed
// each new-line, and quotation mark must be escaped with backslash
#define SHELLSCRIPT "\
	#/bin/bash \n\
	echo \"Hello World!\" \n\
"

int main() {
	puts("Running script...");
	system(SHELLSCRIPT);
	return 0;
}
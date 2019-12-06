// C libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// constants
#define MAXINPUT 1000 // max number of characters supported
#define MAXLIST 6 // number of commands supported
#define clear() printf("\033[H\033[J") // Escape Sequence: clears everything in terminal and places cursor at top

// our created header files
#include "headers/ReadLine.h"

// initializes shell
void init() {
	clear();
	puts("NautonShell implemented by James Ferrarelli and Shane Lopez. OS Fall-2019");
	char* uname = getenv("USER"); // stdlib library function, might have to implement ourselves
	printf("logged in as %s\n", uname);
	sleep(1);
	clear();
}

int main(int argc, char* args[]) {
	init();
	readInput(); // from ReadLine.h
	return 0;
}


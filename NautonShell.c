#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// constants
#define MAXINPUT 1000 // max number of characters supported
#define MAXLIST 8 // number of commands supported

// our created header files
#include "headers/InputBuffer.h"

// main loop for continual use
void shellLoop() {
	char uname[50];
	char cwd[100];
	char *line;
	char **argv;
	int status = 1;

	while(status) {
		getcwd(cwd, 100);
		gethostname(uname, 50); // sets uname to the machine name
		printf("@%s:%s$ ", uname, cwd);
		
		line = readInput();
		argv = parseInput(line);
		status = executeInput(argv);
		
		free(line);
		free(argv);
	}
}

int main(int argc, char** argv) {
	printf("\033[H\033[J"); // Escape Sequence: clears everything in terminal and places cursor at top
	puts("NautonShell implemented by James Ferrarelli and Shane Lopez. OS Fall-2019");

	shellLoop(); // Where all shell stuff happens
	
	return 0;
}


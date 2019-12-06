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
#include "headers/InputBuffer.h"

// main loop for continual use
void shellLoop() {
	char uname[50];
	char *line;
	char **args;
	int status;

	while(status) {
		gethostname(uname, 50); // sets uname to the machine name
		printf("@%s$ ", uname);
		
		line = readInput();
		args = parseInput(line);
		status = executeInput(args);
		puts(line);
		
		free(line);
		free(args);
	}
}

int main(int argc, char* args[]) {
	clear();
	puts("NautonShell implemented by James Ferrarelli and Shane Lopez. OS Fall-2019");

	shellLoop();
	
	return 0;
}


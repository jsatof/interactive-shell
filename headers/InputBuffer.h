#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#include "commands.h"

#define WHITESPACE " \t\r\n\a" // tokens will be separated by whitespace characters
#define BUFFERSIZE 64


/******
	Buffer for handling stdin
*******/

// fetches the line entered by the user
char *readInput() {
	int bufferSize = BUFFERSIZE; // arbitrarily picked a size
	int index = 0;
	char *buffer = malloc(sizeof(char) * bufferSize); 
	int c;

	if(!buffer) { // checks if buffer is a null character
		puts("allocation error: reader received a null character");
		exit(EXIT_FAILURE);
	}	

	// loop through and read the entered line char by char
	while(1) {
		c = getchar();

		// when the entire line is read
		if(c == EOF || c == '\n') {
			buffer[index] = '\0';
			return buffer;
		}
		// else put the char in the string
		else {
			buffer[index] = c; 
		}
		index++;

		// reallocate for when the buffer size is exceeded
		if(index >= bufferSize) {
			bufferSize *= 2; // double the size
			buffer = realloc(buffer, bufferSize);
		
			if(!buffer) { // check again for null character
				puts("allocation error: reader received a null character");
				exit(EXIT_FAILURE);
			}			
		}
	}
}

// detects the entered commands and arguments
char** parseInput(char* line) {
	int bufferSize = BUFFERSIZE;
	int index = 0;
	char **items = malloc(bufferSize * sizeof(char*));
	char *item;

	if(!items) {
		puts("allocation error: parser received null character");
		exit(EXIT_FAILURE);
	}	 

	item = strtok(line, WHITESPACE); // library function that essentially separates a string based on WHITESPACE 
	while(item != NULL) { 			 
		items[index] = item;
		index++;

		// if buffer is exceeded
		if(index >= bufferSize) {
			bufferSize += bufferSize;
			items = realloc(items, bufferSize * sizeof(char*));
			if(!items) {
				puts("allocation error: parser received null character");
				exit(EXIT_FAILURE);
			}
		}

		item = strtok(NULL, WHITESPACE);
		
	}
	items[index] = NULL;
	return items; 
}

// creates process for parsed commands 
int launchInput(char **argv) {
	pid_t pid; 
	int status;

	pid = fork();

	// child process 
	if(pid == 0) {
		if(execvp(argv[0], argv) == -1) {
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if(pid < 0) {
		perror("shell");
	}
	// parent process
	else {
		wait(NULL);
	}
	return 1;
}

int executeInput(char **args) {
	if(args[0] == NULL) {
		return 1;  // empty command entered
	}

	for(int i = 0; i < commandSize(); i++) {
		if(strcmp(args[0], commandString[i]) == 0) {
			return (*commandFunction[i])(args);
		}
	}
	
	return launchInput(args);
}
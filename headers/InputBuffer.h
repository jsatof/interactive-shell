#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#include "commands.h"

#define WHITESPACE " \t\r\n\a" // tokens will be separated by whitespace characters

/******
	Buffer for handling stdin
*******/

// list of valid commands
char *commands[] = {"exit", "help", "cd", "pwd", "mkdir", "rmdir", "chmod", "cp"};

// returns size of commands[]
int sizeOfCommands() {
	return sizeof(commands) / sizeof(char*);
}

// fetches the line entered by the user
char *readInput() {
	int bufferSize = 1024; // arbitrarily picked a size
	int index = 0;
	char *buffer = malloc(sizeof(char) * bufferSize); 
	int c;

	if(!buffer) { // checks if buffer is a null character
		puts("allocation error: buffer received a null character");
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
			bufferSize += 1024; // double the size
			buffer = realloc(buffer, bufferSize);
		
			if(!buffer) { // check again for null character
				puts("allocation error: buffer received a null character");
				exit(EXIT_FAILURE);
			}			
		}
	}
}

// detects the entered commands and arguments
char** parseInput(char* line) {
	int bufferSize = 1024;
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
int launchInput(char **args) {
	pid_t pid; 
	int status;

	pid = fork();

	// child process 
	if(pid == 0) {
		if(execvp(args[0], args) == -1) {
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if(pid < 0) {
		perror("shell");
	}
	// parent process
	else {
		do {
			waitpid(pid, &status, WUNTRACED);
		}
		while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}
#include <stdio.h>
#include <stdlib.h>

// fetches the line entered by the user
char *readInput() {
	int bufferSize = 1024; // arbitrarily picked a size
	int position = 0;
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
			buffer[position] = '\0';
			return buffer;
		}
		// else put the char in the string
		else {
			buffer[position] = c; 
		}
		position++;

		// reallocate for when the buffer size is exceeded
		if(position >= bufferSize) {
			bufferSize += 1024; // double the size
			buffer = realloc(buffer, bufferSize);
		
			if(!buffer) { // check again for null character
				puts("allocation error+: buffer received a null character");
				exit(EXIT_FAILURE);
			}			
		}
	}
}

// detects the entered commands and arguments
void parseInput() {
	
}

// performs the parsed command
void execute() {
	
}
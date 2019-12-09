#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// This file contains all command implementation

// declaring the functions to be implemented
int shell_exit();
int shell_help();
int shell_cd(char **args);
int shell_pwd(char **args);
int shell_mkdir(char **args);
int shell_rmdir(char **args);
int shell_chmod(char **args);
int shell_cp(char **args);


// list of available commands
char *commandString[] = {"exit", "help", "cd", "pwd", "mkdir", "rmdir", "chmod", "cp"};

int (*commandFunction[]) (char **) = { &shell_exit, &shell_help, &shell_cd, &shell_pwd, &shell_mkdir, &shell_rmdir, &shell_chmod, &shell_cp };

// returns length of commands[]
int commandSize() {
	return sizeof(commandString) / sizeof(char*);
}

// change all the return types and parameters passed as see fit
<<<<<<< HEAD
int shell_cd(char **args) {
	
}

int shell_pwd(char **args) {
	
=======

// change all the return types and parameters passed as see fit
void shell_cd(char *path) {
        chdir(path);
}

void shell_pwd() {
        char cwd[1024];
        printf("%s\n",getcwd(cwd, sizeof(cwd)));
>>>>>>> 7da234d3791928b133cd683b9adb1fb5fb1d4a94
}

int shell_mkdir(char **args) {
	
}

int shell_rmdir(char **args) {
	
}

int shell_chmod(char **args) {
	
}

int shell_cp(char **args) {
	
}

// below are a couple of functions for more accessibility 

int shell_exit() {
	return 0;
}

int shell_help() {
	puts("NautonShell implementation by James Ferrarelli and Shane Lopez, OS Fall 2019");
	puts("Enter valid command names, followed by any arguments they require");
	puts("Here are our available commands: ");
	for(int i = 0; i < commandSize(); i++) {
		printf("	%s\n", commandString[i]);
	}
	return 1;	
}


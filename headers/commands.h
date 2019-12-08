#include <stdio.h>
#include <stdlib.h>

// This file contains all command implementation

// list of available commands
static char *commands[] = {"exit", "help", "cd", "pwd", "mkdir", "rmdir", "chmod", "cp"};

// returns length of commands[]
static int sizeOfCommands() {
	return sizeof(commands) / sizeof(char*);
}

// change all the return types and parameters passed as see fit
void shell_cd(char **args) {
	
}

void shell_pwd(char **args) {
	
}

void shell_mkdir(char **args) {
	
}

void shell_rmdir(char **args) {
	
}

void shell_chmod(char **args) {
	
}

void shell_cp(char **args) {
	
}

// below are a couple of functions for more accessibility 

int shell_exit() {
	return 0;
}

int shell_help() {
	puts("NautonShell implementation by James Ferrarelli and Shane Lopez, OS Fall 2019");
	puts("Enter valid command names, followed by any arguments they require");
	puts("Here are our available commands: ");
	for(int i = 0; i < sizeOfCommands(); i++) {
		printf("	%s\n", commands[i]);
	}
	return 1;	
}


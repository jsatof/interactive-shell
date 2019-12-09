#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>


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
int shell_cd(char *path) {
        chdir(path);
        return 1;
}

int shell_pwd() {
        char cwd[1024];
        printf("%s\n",getcwd(cwd, sizeof(cwd)));
        return 1;
}

int shell_mkdir(char *dir) {
        mkdir(dir);
        printf("made new directory %s\n",dir);
        return 1;
}

int shell_rmdir(char *dir) {
        rmdir(dir);
        printf("removed directory %s\n",dir);
        return 1;
}

int shell_chmod(char *permissions, char *path) { //needs 4 characters, always starts with 0
        chmod(path,strtol(permissions,0,8));
        return 1;
}


int shell_cp(char *loc1, char *loc2) {

        return 1;
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


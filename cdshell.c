#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
//Chase Deets
//chd5hq@virginia.edu
//CS 4414-001 - Project 1: Implementing a Shell in C
//currently compiled with: gcc -lreadline -std=c11 cdshell.c -o cdshell

//returns an int after populating an array of token groups
//input: line from commandline, array of strings for arguments
int parseTok(char* cmdline, char** args)
{
	int numArgs = 0;
	char s[64];
	strcpy(s, cmdline);
	char *tok;

	if(!tok){
		fprintf(stderr, "failed to tokenize input, exiting...\n");
		return -1;
	}

	tok = strtok(s, " ");
	while(tok != NULL) {
		printf("tok: %s\n", tok);
		args[numArgs] = malloc(strlen(tok)+1);
		strcpy(args[numArgs], tok);
		printf("arg: %s - ", args[numArgs]);
		//args[numArgs] = strdup(tok);
		//args[numArgs] = strcpy(args[numArgs], tok);
		//printf("added arg: %s\n", args[numArgs]);
		numArgs++;
		
		printf("%d\n", numArgs);
		tok = strtok(NULL, " "); //pass null to continue strtok on tok
		
	}
	//args[numArgs] = NULL;
	printf("done, returning args..");
	return numArgs;
}





int main(int argc, char** argv)
{
	printf("- Starting Shell...\n");
	printf("-- CDShell V0.1 --\n");
	
	int numCmds;
	char *inpt;
	//char **tokenGroup = malloc(256 * sizeof(char*));
	char **tokenGroup;

	while(1)
	{
		inpt = readline(">>> ");
		add_history(inpt);	//allows for repeating previous cmds
		
		if((strcmp(inpt, "exit") == 0) || (strcmp(inpt, "Exit") == 0)){
			printf("Exiting shell... Ciao!\n");			
			exit(0);
		}

		numCmds = parseTok(inpt, tokenGroup);
		
		
		printf("successful parse! numCmds: %d\n", numCmds);
		
		for(int i = 0; i < numCmds; i++)
			printf("arg: %s\n", tokenGroup[i]);
		
		//char *temp;
		//while(tokenGroup){
			//temp = strcpy(temp, tokenGroup[i]);
		//	printf("%s ", tokenGroup[i]);
		//	i++;
		//}			

		free(inpt);
		//free(temp);
		//free(tokenGroup);
	}
	
	




	return 0;
}


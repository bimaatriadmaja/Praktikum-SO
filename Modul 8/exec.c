#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char*argv[]) {
	
	pid_t pid;
	int i;
	
	if (argc != 3)
	{
		printf("\nInsufficient arguments to load program"); 
		printf("\nUsage: ./a.out <path> <cmd>\n");
		exit(-1);
	}

	switch(pid = fork()) 
	{
	case -1:
		printf("fork failed");
		exit(-1);
	case 0:
		printf("Child process\n");
		i = execl(argv[1], argv[2], (void*)0);
		if (i < 0) 
		{
			printf("%s program not loaded using exec system call\n", argv[2]);
			exit(-1);
		}
	default:
		printf("Child Terminated\n");
		exit(0);
	}
}

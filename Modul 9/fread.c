#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd, i;
	char buf[100];
	if (argc < 2) 
	{
		printf("Usage: ./a.out <filename>\n");
		exit(-1);
	}
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("%s file does not exist\n", argv[1]);
		exit(-1);
	}
	
	printf("I = i dari file %s adalah : \n", argv[1]);
	while (read(fd, buf, sizeof(buf)) > 0)
	{
		printf("%s", buf);		
	}
	
	close(fd);
	return 0;
}

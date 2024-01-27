#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd, n, len;
	char buff[100];
	if (argc != 2) 
	{
		printf("Usage: ./a.out <filename>\n"); 
		exit(-1);
	}
	
	fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if (fd < 0) 
	{
		printf("File creation problem\n");
		exit(-1);
	}
	
	printf("Tekan Ctrl+D di akhir baris\n");
	
	while((n = read(0, buff, sizeof(buff))) > 0)
	{
		len = strlen(buff);
		write(fd, buff, len);
	}
	
	close(fd);
	return 0;
}

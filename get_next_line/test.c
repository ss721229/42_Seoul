#include<stdio.h>
#include<fcntl.h>
#include "get_next_line.h"

void populate_expected(char *buffer, int n)
{
	int i = 0;
	while(i < n)
	{
		i += sprintf(buffer + i, "0123456789");
	}
	buffer[n] = 0;
}
int main(){
	int fd;
	char *filename;
	char *ptr;
	//char expected[20002];
	filename = "text";
	fd = open(filename, O_RDWR);
	/*
	populate_expected(expected, 20000);
	expected[20000] = '\n';
	expected[20001] = 0;
	printf("%s",expected);
	write(fd, expected, 20001);
	*/
	while(1)
	{
		ptr = get_next_line(fd);
		if(ptr == NULL)
			break;
		printf("%s", ptr);
	}
	printf("%s", ptr);
	close(fd);
}
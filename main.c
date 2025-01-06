#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd;
	char buffer[999];

	fd = open("test.txt", O_RDONLY);
	read(fd, buffer, 69);
	printf("%s", buffer);
	return 0;

}
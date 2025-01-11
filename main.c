#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd;
	char buffer[999];

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return 0;

}
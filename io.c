/* Program that does I/O and writes "Hello World\n" to a file */


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <assert.h>

int main(int argc, char *argv[]){
	
	int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC | S_IRWXU);
	assert(fd > -1);
	int rc = write(fd, "Hello World\n", 13);
	assert(rc==13);
	close(fd);
	return 0;
}

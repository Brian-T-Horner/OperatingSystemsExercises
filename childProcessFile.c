/* Program to demonstrate accessing a file with child and parent processes and writing to the file at the same time */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char * argv[]){
	int fd = open("./processFile.output", O_CREAT |O_WRONLY | O_TRUNC, S_IRWXU);
	int rc = fork();
	if(rc<0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	}else if(rc == 0){

	}else{

	}
	return 0;
}

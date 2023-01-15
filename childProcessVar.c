/* Program to demonstrate the persistence of variables between parent and child processes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char * argv[]){
	int x = 100;
	int rc = fork();

	if(rc<0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	}else if(rc ==0){
		printf("Child process (pid:%d) x value: %d\n", (int) getpid(), x);
		x=200;
		printf("Child process (pid%d) x value after change: %d\n", (int) getpid(), x);
	}else{
		int rc_wait = wait(NULL);
		printf("Parent process (pid:%d) x value: %d\n", (int) getpid(), x);
		x=300;
		printf("Parent process (pid:%d) x value after change: %d\n", (int) getpid(), x);
	}
return 0;
}


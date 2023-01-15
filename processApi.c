/* Program to create a child process and execute word count on this program. Outputs result to ./processAPI.output */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
	int rc = fork();
	int stdout_fd = dup(STDOUT_FILENO);
	if(rc<0){ //Fork failed - Exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	}else if(rc == 0){ //Child process: redirect standard output to a file
		printf("hello, I am the child (pid:%d)\n", (int) getpid());
		close(STDOUT_FILENO);
		open("./processAPI.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

		// now execute 'wc'...
		char *myargs[3];
		myargs[0] = strdup("wc");            //program "wc" (word count)
		myargs[1] = strdup("processApi.c"); //argument: file to count
		myargs[2] = NULL;		   // marks end of array
		execvp(myargs[0], myargs); 	  // runs word count
		
		dup2(stdout_fd, STDIN_FILENO);	
	}else{ //Parent process: wait
	  int rc_wait = wait(NULL);
	  printf("hello, I am the parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
	}
	return 0;
}

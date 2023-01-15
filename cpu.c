/*Program prints a string given by the user in the format ./cpu <string> to the terminal every second */

//Currently not working with timer.

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <signal.h>

void sigHandler(int Sig){
	(void)Sig;
}

void Spin (int a){
	
	// Handling signal
	struct sigaction sa;
	sa.sa_handler = sigHandler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGALRM, &sa, 0);

	// Timer code for 1 second
	struct itimerval timer1;
	timer1.it_interval.tv_sec = a;
	setitimer(ITIMER_REAL, &timer1, NULL);
}


int main(int arc, char * argv[]){
	if(arc != 2){
		fprintf(stderr, "usage: cpu <string>\n");
		exit(1);
	}
	char *str = argv[1];
	while (1){
		Spin(1000);
		printf("%s\n", str);
	}
	return 0;
}






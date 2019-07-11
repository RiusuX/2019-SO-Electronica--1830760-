#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if(rc<0){
		printf("el fork() falla /n");
	}
	else if (rc>0) {
		// padre 
		sleep(1);
		printf("goodbye\n");
	}
	else {
		// hijo 
		printf("Hello\n");
	}
	return 0;
}

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	pid_t pid1;
	int status1;
	
	if((pid1=fork()) != 0){
		printf("padre (%d, hijo de %d)\n", getpid(), getppid());
	}
	else if(fork() == 0){
		waitpid(pid1, &status1, 0);
		printf("hijo (%d, hijo de %d)\n",getpid(), getppid());
	}
	return 0;
}

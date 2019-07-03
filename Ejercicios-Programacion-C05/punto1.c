#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int x =100;

	printf("pid:%d \n", (int) getpid());
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc == 0) {
		int rm=2;
		x=x+1;
		printf("hola yo soy el hijo %d, y el valor de x: es %d \n", (int) getpid(),x);                
	}
	else {
		wait();
		int jm=4;
		x=x+2;
		printf("hola yo soy el padre de  %d mi pid:%d, y el porcentaje de x: es %d\n",rc, (int) getpid(),x);
	}


	return 0;                                                                                                                                                                                                           	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
int rc = fork();
 if (rc<0) {
 fprintf(stderr, "el fork falla\n");
exit (1);
}

else if (rc>0) {
//Padre
int rc_wait = wait(NULL);
printf("goodbye\n");
} 
else {

//Proceso hijo (nuevo proceso)
int rc_wait = wait(NULL);
printf("Hello\n");
}
return 0;
}

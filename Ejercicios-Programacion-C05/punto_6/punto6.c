#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
int rc = fork();
int status;

if (rc<0) {
fprintf (stderr, "el fork falla\n");
exit (1);
}

else if (rc>0) {
// Padre
waitpid(rc, &status, 0);
printf("goodbye\n");
} else {

// Proceso hijo (nuevo proceso)
wait(NULL);
printf("Hello\n");
}
return 0;
}

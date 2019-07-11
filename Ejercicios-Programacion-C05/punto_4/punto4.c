#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Error\n");
        exit(1);
    }
    
    // Proceso hijo (nuevo proceso)
    else if (rc == 0) 
    {
        printf("----- Ejecutando proceso hijo -----\n");
        char * const argv[] = {"ls", NULL};
        char * const envp[] = {NULL};

        //Descomentar la funcion requerida 

        //execl("/bin/ls", "ls", NULL);
        //execle("/bin/ls", "ls", NULL, envp);
        //execlp("ls", "ls", NULL);
        
        
        //execv("/bin/ls", argv);
        //execvp("ls", argv);
        //execvpe("ls", argv, envp); // 
    }
    
    // Padre
    
    else if (rc > 0);
    {
         wait(NULL);
    }
    return 0;
}

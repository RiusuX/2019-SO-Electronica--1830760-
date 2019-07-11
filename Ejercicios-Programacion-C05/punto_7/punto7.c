#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();

    // Proceso hijo

    if (rc == 0) 
    {
        close(STDOUT_FILENO);
        printf("Hola mundo\n");
    }
    
    // Padre
    else if (rc > 0)
    {
        wait(NULL);
        printf("Soy el padre\n");
    }
    else 
    {
        printf("Ocurrio un error\n");
    }
    return 0;
}


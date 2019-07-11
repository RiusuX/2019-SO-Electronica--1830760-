#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    	FILE* file = fopen("texto.txt", "a");
    	if (file == NULL) {
        fprintf(stderr, "\n fopen() fallo");
    	} 
	else {
        	int rc = fork();
        	if (rc < 0) {
            		fprintf(stderr, "el fork() fallo\n");
            		fclose(file);
            		exit(1);
        	}
		 else if (rc == 0) {
           	 	for (int i=0; i<5; i=i+1) 
			fprintf(file, "Escribiendo desde el niño: %d\n", i);
        	}
		 else {
            		// int wc = wait(NULL); 
            		for (int i=0; i<5; i++) 
                	fprintf(file, "escribiendo desde el padre: %d\n", i);
        	}
        	fclose(file);
	}
	return 0;
}

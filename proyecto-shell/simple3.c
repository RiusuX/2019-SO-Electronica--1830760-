
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	printf("Argumento1: %s\n", argv[1]);
	printf("Argumento2: %s\n", argv[2]);
	printf("Hola ejecucion simple \n");
	printf("%s \n", getenv("PARENT"));
	int a;
	scanf("%d", &a); 
	printf("Numero escaneado recibido fue: %d\n", a);
}


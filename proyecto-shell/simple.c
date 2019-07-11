
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("Hola ejecucion simple \n");
  printf("%s \n", getenv("PARENT"));
}


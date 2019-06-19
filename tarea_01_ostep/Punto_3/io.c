#include <stdio.h>
#include <assert.h>
#include <string.h>


int exists(const char *fname)
{
	FILE *file;
	if((file = fopen(fname, "r")))
	{
		fclose(file);
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	//declaracion de variables
	FILE *fd;
	char archivoTexto[30];

	//copia el string de argv[1] a archivoTexto
	strcpy(archivoTexto, argv[1]);
	//comprueba que el archivo existe
	assert(exists(archivoTexto));
	//abre el archivo con fopen
	fd = fopen(archivoTexto, "r");
	//se inicializa en dos para coger la ultima letra de la cadena de texto
	int i = 2;
	do
	{
		//se reubica el puntero al final, restandole la posicion de i
		fseek(fd, -i, SEEK_END);
		printf("%c", fgetc(fd));
		i = i+1;//se aumenta en 1 i
	}while(ftell(fd)!=1);//cuando el puntero sea igual a 1 se sale del ciclo
	printf("\n");
	fclose(fd);
	return 0;
}


# tarea_01_ostep

## mem
 Se utilizo el mem.c sin ninguna modificacion luego se uso el comando 
sudo sh -c 'echo 0 > /proc/sys/kernel/randomize_va_space' en una terminal 
para desactivar la aletoriedad de la direccion de memoria, finalmente se corre el programa
sincronicamente.

## threads
Se utilizo el threads.c  al cual se le hicieron 3 includes incluido el archivo subido al classroom(mycommon.h). 
Dentro del archivo se dejo tal cual y se le agregaron la variable door de tipo puerta como globarl, al principio del main se uso el
metodo crear_puerta(door); que recibia como parametro la variable door declarada previamente, luego siguio el curso normal del codigo hasta el momento en
que los hilos ejecutan worker, antes de entrar al ciclo de repeticion ambos hilos cierran la puerta, cerrar_puerta(door); y al finalizar el ciclo la abren,
abrir_puerta(door); ambos salian al programa principal despues de terminar de ejecutarse y destruia la puerta, destruir_puerta(door);

## io
Se utilizo el io.c, el cual usaba para su ejecucion un archivo de nombre cualquiera en este caso texto.txt, se copio y pego la funcion exists del word, en el main se declararon dos variables, fd y archivoTexto, FILE y char, usadas para almacenar el apuntador del archivo y el nombre de este, se comprueba que existe el archivo, se abre el archivo con fopen de solo lectura, se declara un i igual a 2 y se ejecuta un ciclo do while que contiene fseek apuntando a fd en la posicion -2 desde el final de la posicion del puntero del archivo de texto, se imprime la letra se aumenta en uno i y se evalua la condicion de salida que pide que el numero de la posicion del puntero sea diferente de 1, al terminar el ciclo cierrar el archivo con fclose y termina el programa.



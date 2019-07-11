Ejercicios-programacion-C05
1. El valor de variable del proceso hijo es igual al declarado inicialmente, antes de ser llamado mediante el fork. Por medio del programa que desarollamos pudimos evidenciar que la variable toma diferentes valores en cada proceso, es decir hay un x diferente en cada proceso.

2. Al tratar de escribir al mismo tiempo, el padre como el hijo en el archivo nuevo lo que va a pasar
 es que se tomara como prioridad, el proceso padre y luego se ejecutara el proceso hijo. 

3. En este programa se hizo uso del comando sleep(#) que realmente hace es parar un determinado tiempo #
por lo cual podemos hacer esperar el padre y asi ejecutar primero el hijo, logrando lo propuesto en el punto. 

4. las diferentes llamadas al sistema exec() se debe a que cada uno de ellas nos permite ingresar
diferentes tipos de argumentos, teniendo la libertad de poder ingresar caminos mas comodos. (arg0 y envp del archivo ejcutable que deseamos reemplazar)

5. La funcion wait () da como respuesta el PID del proceso hijo cuando este varia su estado.
Si wait() es utilizado en el proceso hijo, pero este no posee algun proceso hijo, la llamada de wait () no es tomada en consideracion, por ende continuara su ejecucion, debido a que no se encontrara el proceso hijo al cual se dio la orden de esperar.

6. Seria util hacer uso de la funcion waitpid() en casos cuando es requerido que se espere a que un proceso termine su ejecucion para ejecutar otro, sin necesidad de que este, sea un proceso hijo, ya que permite que se aplique a determinados procesos.

7. Si el hijo llama a printf () para imprimir después de cerrar el descriptor, no se imprime lo que se encuentra en
 el proceso hijo, debido a que la función (STDOUT_FILENO) cierra el stream que permite la salida, por ende impide que se ejecute dicha función.

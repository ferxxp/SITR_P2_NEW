/* Creación, terminación y control de procesos hijo a partir de un proceso padre */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/* Prototipos */ void hijo(void); void padre(void);
/* Variables globales */ pid_t pid;
static int lim=1000;
/* pid_t es un entero que representa el identificador ID de un proceso*/
/* Función principal */
int main (void)
{
/* pid_t fork(): creación de un nuevo proceso, si la operación se realiza de forma satisfactoria, la función fork devuelve al proceso padre el identificador ID del proceso hijo, y al proceso hijo un 0; en caso contrario, se devuelve –1 al proceso padre */
/* Creación de un proceso hijo */ switch(pid = fork())
{
case (pid_t) -1:/* void perror(const char *message): imprime un mensaje de error asociado a la cadena que tiene como argumento */
perror("fork"); exit(EXIT_FAILURE);
case (pid_t) 0: hijo(); break;
default:
padre(); break;
}
/* void exit(int status): esta función termina el proceso con estado status.
El valor de status es un entero comprendido entre 0 y 255. Normalmente se emplea el valor 0 para indicar salida correcta (SUCCESS) y 1 salida por fallo (FAILURE) */
exit(EXIT_SUCCESS);

}
/* Fin función principal */


/* Declaración de las dos funciones que permiten identificar ambos procesos */

void hijo(void)
{
sleep (1); /*Parada del programa durante X segundos*/
printf("Hola soy el proceso hijo \n");
double sum=1;
 for(int i=1;i<lim;i++){
   for(int j=1;j<lim;j++){
     for(int k=1;k<lim;k++){
        sum=sum+i;
        sum=sum-j;
        sum=sum-k;
        }
      }
    }
printf("%f\n", sum);
}

void padre(void)
{
printf("Hola soy el proceso padre \n");
}


/* pid_t waitpid(pid_t pid, int *status, int options): provoca una espera del
proceso padre hasta que el proceso hijo con identificador pid finalice. Si pid es
–1 realiza una espera asociada a la finalización de todos los procesos hijos,
 es decir, se comporta como wait(). La información del estado del proceso hijo se
almacena en status. El tercer argumento es una máscara de bits (deberá valer 0 “OR”).
 La función devuelve el identificador pid del proceso cuyo estado está
proporcionando. */
/* pid_t wait(int *status): provoca una espera del proceso padre hasta que cualquier
 proceso hijo finalice. La información del estado del proceso hijo se almacena en status.*/

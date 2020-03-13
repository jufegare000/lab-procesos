/*

Escriba un programa usando fork(). El proceso hijo imprimirá "Hello"; el proceso padre imprimirá "goodbye". Usted deberá asegurar que el proceso hijo imprima en primer lugar; ¿usted podría hacer esto sin llamar wait() en el padre?

Se puede usar la opción Sleep
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
int parent;
switch(parent = fork()){
      case -1:
         printf("fork error");
      case 0:       //child
         printf("Soy el hijo: Hola pa %d\n", getpid());
         break;
      default:      //parent
         sleep(1);
         printf("Soy el parent, chao pescao (%d)\n", getpid());
         break;
  }
}
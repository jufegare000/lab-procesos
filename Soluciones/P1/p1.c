/*
Escriba un programa que llame un fork(). Antes del llamado del fork(), declare una variable de acceso (por ejemplo, x) y
 asígnele un valor (por ejemplo, 100). Responda las siguientes preguntas:
¿Cuál es el valor de la variable en el proceso hijo?
¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de x?
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int x = 100;
    if (fork() == 0)
    {
        printf("Soy tu qcho %d \n", x);
        x = 50;
        printf("Y te lo cambié %d \n", x);
    }
    else
    {
        printf("Noooo!!!! %d\n", x);
        x = 25;
        printf("Pues yo también cambio prro %d\n", x);
    }
}
/*
Respuestas:
    *Al principio 100
    *Primero se cambia de valor en el hijo luego en el padre
*/
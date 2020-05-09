/*
Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (STDOUT FILENO). ¿Qué pasa si el hijo llama printf() para imprimir alguna salida después de cerrar el descriptor?
*/

#include <errno.h>
#include <stdio.h>
#include <unistd.h>

void main()
{

    if (fork() == 0)
    {
        fclose(stdout);
        printf("lather the son\n");
    }
    else
    {
        printf("first the father\n");
    }
    return 0;
}

/*
    No se ejecuta el print del hijo
*/
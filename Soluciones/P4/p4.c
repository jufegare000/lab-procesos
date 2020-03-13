/*
Escriba un programa que llame fork() y entonces llame alguna forma de exec() para correr el programa /bin/ls. Intente probar todas las variaciones de la familia de funciones exec() incluyendo (en linux) execl(), execle(), execlp(), execv(), execvp() y execvpe(). ¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica?
*/


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *const parmList[] = {"/bin/ls", "-l", NULL};
    char *const envParms[2] = {"STEPLIB=SASC.V6.LINKLIB", NULL};
    if(fork()==0){
       
       printf("hijo\n");
       usingExecl();
       usingExelp();
       usingExeve(parmList, envParms);
    }
    else{
       sleep(2);
       printf("padre\n");
       usingExecl();
       usingExelp();
       usingExeve(parmList, envParms);
    }
    
}

void usingExecl(){
    execl("/bin/ls","/bin/ls",NULL);
}

void usingExelp(){
    execlp("/bin/ls","/bin/ls",NULL);
}

void usingExeve(char *const paramList[], char *const envParams[]){
    execve("/bin/ls",paramList,envParams);
}


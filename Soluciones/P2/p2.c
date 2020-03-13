/*
Escriba un programa que abra un archivo (con la llamada open()) y entonces llame a fork(). 
¿Pueden el padre y el hijo acceder al file descriptor retornado por open()?
¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?


*/

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h> 
#include <fcntl.h> 

extern int errno;
int main()
{
    // if file does not have in directory
    // then file foo.txt is created.
    //read();
    write();
    return 0;
}

int read(){
    int fd, sz;
    char *c = (char *)calloc(100, sizeof(char));

    fd = open("text.txt", O_RDONLY);
    //fork();
    printf("/n fd = %d/n", fd);

    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }

    sz = read(fd, c, 100);
    printf("called read(% d, c, 10).  returned that"
           " %d bytes  were read.\n",
           fd, sz);
    c[sz] = '\0';
    printf("Those bytes are as follows: % s\n", c);
    return 0;
}

int write(){
    int sz; 
  
  int fd = open("text.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); 
  fork();
  if (fd < 0) 
  { 
     perror("r1"); 
     exit(1); 
  } 
  
  sz = write(fd, "fokienmen gonorsofia\n", strlen("fokienmen gonorsofia\n")); 
  
  printf("called write(% d, \"fokienmen gonorsofia\\n\", %d)."
    " Ha retornao: %d\n", fd, strlen("fokienmen gonorsofia\n"), sz); 
  
  close(fd); 
   return 0;
} 


/*
    *No pueden a menos que se haga una segmentación de los bytes leídos por padre para que el hijo pueda leer la misma cantidad que le sucede.
    
    *Se sopone que el gestor de procesos debe permitir editar el mismo archivo a la vez, pero si tratan de escribir la misma línea al tiempo presenta problemas.


*/
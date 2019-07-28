#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int sz;
    char *c;
    int x = open("/home/santiago/Documentos/UdeA/SO/laboratorio_1_procesos/hola.txt", O_WRONLY | O_CREAT | O_TRUNC, 644);
    int rc = fork();

    if (rc == 0)
    {
        char a[] = "Soy el hijo\n\0";
        sz = write(x, a, strlen(a));
        c = "Fin del hijo\n\0";
    }
    else
    {
        // wait(NULL);
        char b[] = "Soy el padre\n\0";
        sz = write(x, b, strlen(b));
        // wait(NULL);
        c = "Fin del padre\n\0";
    }
    sz = write(x, c, strlen(c));
    printf("Fin del programa. (File descriptor %d)\n", x);

    return 0;
}
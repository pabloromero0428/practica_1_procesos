#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    int w;

    if (rc == 0)
    {
        w = wait(NULL);
        printf("Soy el hijo, y la funcion wait instaciada en el hijo retorna %d\n", w);
    }
    else
    {
        w = wait(NULL);
        printf("Soy el padre, el PID de mi hijo es %d y la función wait() retorna %d\n", rc, w);
    }

    return 0;
}
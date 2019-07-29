#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0)
    {
        printf("El fork ha fallado\n");
    }
    else if (rc == 0)
    {
        printf("Estoy en el proceso hijo %d\n", (int)getpid());
        close(STDOUT_FILENO);
        printf("Cerrada la salida estándar\n");
    }
    else
    {
        printf("Estoy en el proceso padre %d\n", (int)getpid());
    }

    return 0;
}
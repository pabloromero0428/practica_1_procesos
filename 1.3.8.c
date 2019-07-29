#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd[2], pid1, pid2;
    char readbuffer[30];

    pipe(fd);
    pid1 = fork();

    if (pid1 < 0)
    {
        printf("El fork ha fallado\n");
    }
    else if (pid1 == 0)
    {
        char message[] = "¡Sistemas Operativos!\n";
        close(fd[0]);
        printf("El proceso %d manda: %s", (int)getpid(), message);
        write(fd[1], message, (strlen(message) + 1));
    }
    else
    {
        pid2 = fork();
        if (pid2 < 0)
        {
            printf("El fork ha fallado\n");
        }
        else if (pid2 == 0)
        {
            close(fd[1]);
            read(fd[0], readbuffer, sizeof(readbuffer));
            printf("El proceso %d recibió: %s", (int)getpid(), readbuffer);
        }
        else
        {

            printf("Estoy en el proceso padre %d\n", (int)getpid());
        }
    }

    return 0;
}
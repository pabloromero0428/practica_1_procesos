#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    int status;
    pid_t w;
    
    if (rc == 0)
    {
        printf("Soy el hijo %d y mi padre me va a esperar mientras duermo.\n", (int)getpid());
        sleep(2);
        printf("Ya desperté, gracias por esperarme.\n");
    }
    else
    {
        printf("Soy el padre y estoy esperando a mi hijo %d.\n", rc);
        do
        {
            w = waitpid(rc, &status, WNOHANG);
            if (w == -1)
                perror("waitpid() error");
            else if (w == 0)
            {
                printf("Mi hijo está durmiendo.\n");
                sleep(2);
            }
            else
            {
                if (WIFEXITED(status))
                {
                    printf("Mi hijo ya despertó.\n");
                }
            }
        } while (w == 0);
    }

    return 0;
}
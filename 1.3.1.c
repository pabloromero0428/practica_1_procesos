#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();
    if (rc < 0)
    {
        printf("El fork ha fallado\n");
    }
    else if (rc == 0)
    {
        printf("Estoy en el proceso hijo %d, y el valor de x es %d\n", (int)getpid(), x);
        x += 500;
    }
    else
    {
        printf("Estoy en el proceso padre %d, y el valor de x es %d\n", (int)getpid(), x);
        x += 200;
    }

    printf("El valor final para x en mi proceso %d es %d \n", (int)getpid(), x);

    return 0;
}
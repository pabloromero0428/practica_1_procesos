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
        printf("Hello\n");
    }
    else
    {
        sleep(1);
        printf("Goodbye\n");
    }

    return 0;
}
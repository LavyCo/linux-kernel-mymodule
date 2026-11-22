
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;

    fd = open("/dev/mymodule", O_RDONLY);

    if (fd < 0)
    {
        perror("open failed");
        return 1;
    }

    printf("Device opened successfully\n");

    if (close(fd) < 0)
    {
        perror("close failed");
        return 1;
    }

    printf("Device closed successfully\n");

    return 0;
}

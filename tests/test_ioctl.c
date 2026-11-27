#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "mymodule.h"

int main(void)
{
    int fd;
    struct mystats stats;

    fd = open("/dev/mymodule", O_RDWR);

    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    if (ioctl(fd, MY_STATSGET, &stats) < 0)
{
    perror("ioctl MY_STATSGET");
    close(fd);
    return 1;
}
    printf("Open count: %u\n", stats.open_count);
    printf("Release count: %u\n", stats.release_count);
    printf("Active count: %u\n", stats.active_count);

    printf("\nClearing statistics...\n");

    if (ioctl(fd, MY_STATSCLR, 0) < 0)
    {
        perror("ioctl MY_STATSCLR");
        close(fd);
        return 1;
    }
    if (ioctl(fd, MY_STATSGET, &stats) < 0)
    {
        perror("ioctl MY_STATSGET");
        close(fd);
        return 1;
    }

    printf("\nStatistics after clearing:\n");
    printf("Open count: %u\n", stats.open_count);
    printf("Release count: %u\n", stats.release_count);
    printf("Active count: %u\n", stats.active_count);

    close(fd);

    return 0;
}
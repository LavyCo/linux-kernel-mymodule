
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 128

int main(void)
{
    int fd;
    char write_buf[BUFFER_SIZE];
    char read_buf[BUFFER_SIZE] = {0};
    size_t read_size;
    ssize_t written, bytes_read;

    fd = open("/dev/mymodule", O_RDWR);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("Enter text to write: ");
    if (fgets(write_buf, sizeof(write_buf), stdin) == NULL) {
        close(fd);
        return 1;
    }

    write_buf[strcspn(write_buf, "\n")] = '\0';

    printf("Enter number of bytes to read (1-127): ");
    if (scanf("%zu", &read_size) != 1 ||
        read_size == 0 || read_size >= BUFFER_SIZE) {
        printf("Invalid size\n");
        close(fd);
        return 1;
    }

    written = write(fd, write_buf, strlen(write_buf));

    if (written < 0) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Bytes written: %zd\n", written);

    bytes_read = read(fd, read_buf, read_size);

    if (bytes_read < 0) {
        perror("read");
        close(fd);
        return 1;
    }

    read_buf[bytes_read] = '\0';

    printf("Bytes requested: %zu\n", read_size);
    printf("Bytes read: %zd\n", bytes_read);
    printf("Data read: %s\n", read_buf);

    close(fd);
    return 0;
}

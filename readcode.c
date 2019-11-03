#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <unistd.h>

#include <errno.h>
#include <stdio.h>

int main() {
    int fd = open("code.txt", O_RDWR);

    if (fd == -1) {
        perror("open failed");
        return errno;
    }

    unsigned char ch;
    while(read(fd, &ch, 1))
        printf("%3x ", ch);
    printf("\n");

    lseek(fd, 0, SEEK_SET);

    while (read(fd, &ch, 1))
        printf("%3d ", ch);
    printf("\n");
    
    close(fd);
    return 0;
}

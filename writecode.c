#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <unistd.h>

#include <errno.h>
#include <stdio.h>

int main() {
    int fd = open("/home/swebert/Documents/correaswebert/8085-Simulator/code.txt", O_RDWR);

    if (fd == -1) {
        perror("open failed");
        return errno;
    }
    
    int hexcode;
    while (hexcode != -1) {
        scanf("%d", &hexcode);
        printf("0x%x\n", hexcode);
        write(fd, &hexcode, 1);
    }
    
    close(fd);
    return 0;
}

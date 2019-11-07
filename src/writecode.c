#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <unistd.h>

#include <errno.h>
#include <stdio.h>

#include <string.h>
#include <math.h>

int toHex(const char *string)
{
    int len = strlen(string), num = 0, i = len;
    char ch;

    while((ch = string[--i]) != '\0')
    {
        if ('0' <= ch && ch <= '9')
            num += pow(16, len - i - 1) * (ch - '0');
        else if ('A' <= ch && ch <= 'F')
            num += pow(16, len - i - 1) * (ch - 'A' + 10);
        else if ('a' <= ch && ch <= 'f')
            num += pow(16, len - i - 1) * (ch - 'a' + 10);
    }
    
    return num;
}

int main(int argc, char *argv[]) {
    if (argc < 2)
    {
        errno = EINVAL;
        perror("bad arguments");
        return errno;
    }

    int fd = open(argv[1], O_WRONLY|O_CREAT);
    if (fd == -1) {
        perror("open failed");
        return errno;
    }
    
    char chexcode[3];
    int ihexcode;
    while (1) {
        scanf("%s", chexcode);
        ihexcode = toHex(chexcode);
        if (ihexcode == 256)
            break;
        write(fd, &ihexcode, 1);
    }
    
    close(fd);
    return 0;
}

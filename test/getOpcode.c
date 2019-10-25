#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "getOpcode.c"

int main(int argc, char const *argv[])
{
    int fd = open("codefile.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open failed");
        return EINVAL;
    }
    
    return 0;
}

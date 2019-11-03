#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../include/hex2mneumonic.h"


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

int main() {
    char hex[2];
    while (1)
    {
        scanf("%s", hex);
        printf("%2x %s\n", toHex(hex), opcodes[toHex(hex)]);
    }
    return 0;
}

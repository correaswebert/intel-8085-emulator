#include <string.h>
#include <stdio.h>

int main() {
    char data[3];
    scanf("%s", data);
    scanf("%s", data);
    printf("%s\n", data);
    if(!strcmp("-1", data))
        printf("Equal!\n");
    return 0;
}

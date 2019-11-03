#include <string.h>
#include <stdio.h>
#include <stdint.h>

void incr(uint16_t *num) {
    *num = *num + 1;
}

int main() {
    uint8_t x = 1;
    printf("x = %d\n", x);
    incr((uint16_t *) &x);
    printf("x = %d\n", x);
    return 0;
}

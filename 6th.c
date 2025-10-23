#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return (x & ~(~(~0 << n) << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
}
int main() {
    unsigned x = 0b11101000;
    unsigned y = 0b00001111; 
    int p = 4, n = 2;
    unsigned result = setbits(x, p, n, y);
    printf("setbits result: %u \n", result, result);
    return 0;
}

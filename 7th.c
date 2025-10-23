#include <stdio.h>
unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << (p + 1 - n));
}
int main() {
    unsigned x = 0b10101000; 
    int p = 5, n = 3;
    unsigned result = invert(x, p, n);
    printf("invert result: %u\n", result);
    return 0;
}

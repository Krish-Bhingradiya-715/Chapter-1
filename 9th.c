#include <stdio.h>
int bitcount(unsigned x) {
    int count = 0;
    while (x) {
        x &= (x - 1);
        count++;
    }
    return count;
}
int main() {
    unsigned x;
    printf("Enter a positive integer: ");
    scanf("%u", &x);
    printf("Number of 1-bits in %u is %d\n", x, bitcount(x));
    return 0;
}

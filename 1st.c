#include <stdio.h>
int main() {
    printf("Ranges :\n");
    printf("signed char: %d to %d\n", -(1 << 7), (1 << 7) - 1);
    printf("unsigned char: 0 to %u\n\n", (1U << 8) - 1);
    printf("signed short: %d to %d\n", -(1 << 15), (1 << 15) - 1);
    printf("unsigned short: 0 to %u\n\n", (1U << 16) - 1);
    unsigned long long max_int = (1ULL << 31) - 1;
    printf("signed int: %d to %d\n", -(long long)(max_int) - 1, (long long)max_int);
    printf("unsigned int: 0 to %u\n\n", (1ULL << 32) - 1);
    unsigned long long max_long = (1ULL << 63) - 1;
    printf("signed long: %d to %d\n", -(long long)(max_long) - 1, (long long)max_long);
    printf("unsigned long: 0 to %u\n", ~0ULL); 
    return 0;
}


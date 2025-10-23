#include <stdio.h>
unsigned rightrot(unsigned x, int n) {
    int word_size = sizeof(x) * 8;  
    n = n % word_size;               
    return (x >> n) | (x << (word_size - n));
}
int main() {
    unsigned x = 0b10110010; // 176
    int n = 3;
    unsigned result = rightrot(x, n);
    printf("rightrot result: %u\n", result);
    return 0;
}

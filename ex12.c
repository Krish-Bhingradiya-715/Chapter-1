#include <stdio.h>
#define IN 1  
#define OUT 0 
int main() {
    int c, s;
    s = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (s == IN) {
                putchar('\n');  
                s = OUT;
            }
        } else {
            putchar(c);      
            s = IN;
        }
    }
    return 0;
}

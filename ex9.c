#include <stdio.h>
int main() {
    int c;
    int p = 0; 
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!p) { 
                putchar(c);
                p = 1; 
            }
        } else {
            putchar(c);      
            p = 0;   
        }
    }
    return 0;
}


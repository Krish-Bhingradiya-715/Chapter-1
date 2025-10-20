#include <stdio.h>
int main() {
    int c, p= 0;
    int n = 4; 
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = n - (p % n); 
            for (int i = 0; i < spaces; i++) {
                putchar(' ');
                p++;
            }
        } else {
            putchar(c);
            p++;
            if (c == '\n') p = 0;
        }
    }
    return 0;
}

#include <stdio.h>
int main() {
    int c, i, l = 100;
    char s[l];
    for (i = 0; i < l - 1; ++i) {
        c = getchar();
        if (c == EOF)
            break;
        if (c == '\n')
            break;
        s[i] = c;
    }
    s[i] = '\0'; 
    printf("input: %s\n", s);
    return 0;
}

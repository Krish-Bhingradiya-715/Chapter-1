#include <stdio.h>
int main() {
    int m = 1000;
    char line[m];
    int c, i, len;
    while (1) {
        i = 0;
        while (i < m - 1 && (c = getchar()) != EOF && c != '\n') {
            line[i++] = c;
        }
        if (c == '\n') {
            line[i++] = c;
        }
        line[i] = '\0';
        len = i;
        if (len == 0 && c == EOF) break;
        if (len > 80) {
            printf("%s", line);
        }
    }
    return 0;
}

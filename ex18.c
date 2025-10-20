#include <stdio.h>
int main() {
    int maxline = 1000;
    char line[maxline];
    int c, i, len, j;
    while (1) {
        i = 0;
        while (i < maxline - 1 && (c = getchar()) != EOF && c != '\n') {
            line[i++] = c;
        }
        if (c == '\n') {
            line[i++] = c;
        }
        line[i] = '\0';
        len = i;
        if (len == 0 && c == EOF) break;
        for (j = len - 1; j >= 0; j--) {
            if (line[j] != ' ' && line[j] != '\t' && line[j] != '\n') break;
        }
        line[j + 1] = '\n';
        line[j + 2] = '\0';
        if (j >= 0)
            printf("%s", line);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
int main() {
    int maxline = 1000;
    char line[maxline];
    int c, i, len, j;
    char temp;
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
        if (line[len - 1] == '\n') len--;
        for (i = 0, j = len - 1; i < j; i++, j--) {
            temp = line[i];
            line[i] = line[j];
            line[j] = temp;
        }
        printf("%s", line);
        if (c == '\n') printf("\n");
    }
    return 0;
}

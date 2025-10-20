#include <stdio.h>
#include <string.h>
int main() {
    int maxline = 1000;
    char line[maxline], longest[maxline];
    int len, max = 0, t;
    while (1) {
        int i = 0;
        int c;
        t= 0;
        while (i < maxline - 1 && (c = getchar()) != EOF && c != '\n') {
            line[i++] = c;
        }
        if (c == '\n') {
            line[i++] = c;
        }
        line[i] = '\0';
        len = i;
        if (len == 0 && c == EOF) break;
        t += len;
        if (t > max) {
            max = t;
            strcpy(longest, line);
        }
    }
    if (max > 0) {
        printf("Longest line :\n%s", longest);
        printf("Length of longest line is : %d\n", max);
    }
    return 0;
}

#include <stdio.h>
void remove_comments() {
    int c, d;
    int in_comment = 0;
    while ((c = getchar()) != EOF) {
        if (in_comment) {
            if (c == '*' && (d = getchar()) == '/') in_comment = 0;
            else if (d != EOF) ungetc(d, stdin);
        } else {
            if (c == '/' && (d = getchar()) == '*') in_comment = 1;
            else {
                if (d != EOF) ungetc(d, stdin);
                putchar(c);
            }
        }
    }
}
int main() {
    remove_comments();
    return 0;
}


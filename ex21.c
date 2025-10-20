#include <stdio.h>
void entab(int n);
int main() {
    entab(4);
    return 0;
}
void entab(int n) {
    int c, pos = 0, count = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            count++;
            if ((pos + count) % n == 0) {
                putchar('\t');
                pos += count;
                count = 0;
            }
        } else {
            for (int i = 0; i < count; i++) {
                putchar(' ');
                pos++;
            }
            count = 0;
            putchar(c);
            pos++;
            if (c == '\n') pos = 0;
        }
    }
}

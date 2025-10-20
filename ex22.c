#include <stdio.h>
#include <string.h>
void f(int n) {
    char line[1000];
    while (fgets(line, sizeof(line), stdin)) {
        int len = strlen(line), start = 0, last_blank;
        while (start < len) {
            int end = start + n;
            if (end >= len) end = len;
            last_blank = -1;
            for (int i = start; i < end; i++) {
                if (line[i] == ' ' || line[i] == '\t') last_blank = i;
            }
            if (last_blank != -1) end = last_blank + 1;
            for (int i = start; i < end; i++) putchar(line[i]);
            putchar('\n');
            start = end;
        }
    }
}
int main() {
    int max = 20;
    f(max);
    return 0;}

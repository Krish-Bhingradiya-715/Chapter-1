#include <stdio.h>
#include <ctype.h>
#define NUMBER '0'
int getop(char s[]) {
    int i, c;
    static int lastc = 0;
    if (lastc != 0) {
        c = lastc;
        lastc = 0;
    } else
        c = getchar();
    while ((s[0] = c) == ' ' || c == '\t')
        c = getchar();
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if (c == '-' || isdigit(c)) {
        if (c == '-')
        {
            int next = getchar();
            if (!isdigit(next) && next != '.') {
                lastc = next;
                return '-'; 
            }
            s[++i] = next;
            c = next;
        }
        if (isdigit(c))
            while (isdigit(s[++i] = c = getchar()))
                ;
        if (c == '.')
            while (isdigit(s[++i] = c = getchar()))
                ;
        s[i] = '\0';
        if (c != EOF)
            lastc = c;
        return NUMBER;
    }

    return c;
}
int main() {
    char s[100];
    int type;
    printf("Enter input: ");
    type = getop(s);
    if (type == NUMBER)
        printf("You entered a number: %s\n", s);
    else
        printf("You entered an operator: %c\n", type);
    return 0;
}

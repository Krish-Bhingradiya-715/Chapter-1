#include <stdio.h>
#include <string.h>
#define BUFSIZE 100
char buf[BUFSIZE]; 
int bufp = 0;       
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) {
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("ungetch: buffer full\n");
}
void ungets(char s[]) {
    int len = strlen(s);
    while (len > 0) {
        ungetch(s[--len]);  
    }
}
int main() {
    char s[] = "Hello\n";
    int c;
    printf("Pushing back string: %s", s);
    ungets(s);
    printf("Reading again:\n");
    while ((c = getch()) != EOF)
        putchar(c);
    return 0;
}

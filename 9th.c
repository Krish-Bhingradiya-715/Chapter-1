#include <stdio.h>
int buf;
int buf_full = 0;
int getch(void) {
    if (buf_full) {
        buf_full = 0;
        return buf;      
    } else {
        return getchar(); 
    }
}
void ungetch(int c) {
    if (buf_full) {
        printf("ungetch: buffer already full\n");
    } else {
        buf = c;         
        buf_full = 1;
    }
}
int main() {
    int c;
    printf("Enter a character (Ctrl+D to send EOF):\n");
    c = getch();
    if (c == EOF)
        printf("You entered EOF directly!\n");
    else {
        printf("Got: %c\n", c);
        printf("Pushing it back...\n");
        ungetch(c);
        c = getch();
        if (c == EOF)
            printf("EOF read again.\n");
        else
            printf("Read again: %c\n", c);
    }
    printf("Now testing pushback of EOF manually...\n");
    ungetch(EOF);
    if (getch() == EOF)
        printf("EOF handled correctly!\n");
    return 0;
}

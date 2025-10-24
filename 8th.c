#include <stdio.h>
int buf = 0;      
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
    if (buf_full)
        printf("ungetch: buffer already full\n");
    else {
        buf = c;
        buf_full = 1;
    }
}
int main() {
    int c;
    printf("Type a word: ");
    c = getch();    
    printf("First char: %c\n", c);
    printf("Pushing it back...\n");
    ungetch(c);
    printf("Reading again: %c\n", getch());
    return 0;
}

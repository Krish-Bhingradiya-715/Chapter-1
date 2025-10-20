#include <stdio.h>
int main() {
    int c;          
    int b = 0; 
    int t = 0;  
    int nl = 0; 
    printf("Enter text :\n");
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            b++;
        else if (c == '\t')
            t++;
        else if (c == '\n')
            nl++;
    }
    printf("\nCounts:\n");
    printf("Blanks  : %d\n", b);
    printf("Tabs    : %d\n", t);
    printf("Newlines: %d\n", nl);
    return 0;
}

#include <stdio.h>
#define IN 1   
#define OUT 0  
#define MAXWORD 20  
int main() {
    int c, i, s, len;
    int wordlen[MAXWORD + 1]; 
    s = OUT;
    for (i = 0; i <= MAXWORD; i++)
        wordlen[i] = 0;
    len = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (s == IN) {
                s = OUT;
                if (len > MAXWORD)
                    len = MAXWORD;  
                wordlen[len]++;
                len = 0;
            }
        } else {
            s = IN;
            len++;
        }
    }
    printf("\nHorizontal Histogram of Word Lengths:\n");
    for (i = 1; i <= MAXWORD; i++) {
        printf("%d: ", i);
        for (int j = 0; j < wordlen[i]; j++)
            printf("!");
        printf("\n");
    }
    if (wordlen[MAXWORD] > 0)
        printf("%d: %d word(s) longer than %d\n", MAXWORD, wordlen[MAXWORD], MAXWORD);
    return 0;
}

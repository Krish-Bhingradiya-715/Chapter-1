#include <stdio.h>
#define M 128  
int main() {
    int c;
    int freq[M] = {0};
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < M)
            freq[c]++;
    }
    for (int i = 32; i < M; i++) { 
        if (freq[i] > 0) {
            printf("%c: ", i);
            for (int j = 0; j < freq[i]; j++)
                printf("!");
            printf("\n");
        }
    }
    return 0;
}

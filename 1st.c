#include <stdio.h>
int strindex(char s[], char t[]) {
    int i, j, k;
    int rightmost = -1; 
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0') {
            rightmost = i; 
        }
    }
    return rightmost;
}
int main() {
    char str[] = "MOSCHIP IS A GREATE COMPANY TO WORK";
    char pattern[] = "ould";
    int index = strindex(str, pattern);
    if (index >= 0)
        printf("Rightmost occurrence of \"%s\" in \"%s\" is at index %d\n", pattern, str, index);
    else
        printf("Pattern not found\n");
    return 0;
}

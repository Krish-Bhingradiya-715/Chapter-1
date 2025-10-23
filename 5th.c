#include <stdio.h>
#include <string.h>
void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
void itob(int n, char s[], int b) {
    int i = 0;
    int sign = n;
    long num = n;
    char digits[] = "0123456789ABCDEF";
    if (num < 0) num = -num;
    do {
        s[i++] = digits[num % b];
    } while ((num /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int main() {
    char s[20];
    itob(250, s, 16);
    printf("%s\n", s); 
}

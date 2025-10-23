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
void itoa_safe(int n, char s[]) {
    int i = 0;
    int sign = n;
    long num = n;         
    if (num < 0) num = -num;
    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int main() {
    char s[20];
    itoa_safe(-2147483648, s);
    printf("%s\n", s);  
}

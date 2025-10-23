#include <stdio.h>
#include <string.h>
void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
void itob(int n, char s[], int b) {
    int i = 0, sign = n;
    unsigned int num;  
    if (b < 2 || b > 16) {
        s[0] = '\0';  
        return;
    }
    num = (n < 0 && b == 10) ? -n : (unsigned int)n;  
    do {
        int digit = num % b;
        s[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
        num /= b;
    } while (num > 0);
    if (sign < 0 && b == 10)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int main() {
    char s[50];
    int n = -250;
    itob(n, s, 10);  
    printf("Decimal: %s\n", s);
    itob(n, s, 2);  
    printf("Binary : %s\n", s);
    itob(n, s, 16);   
    printf("Hex    : %s\n", s);
    itob(n, s, 8);    
    printf("Octal  : %s\n", s);
    return 0;
}

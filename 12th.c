#include <stdio.h>
void itoa_recursive(int n, char s[]);
void helper(int n, char s[], int *index);
void itoa_recursive(int n, char s[]) {
    int sign = n;
    if (n < 0)
        n = -n;
    int i = 0;
    helper(n, s, &i);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
}
void helper(int n, char s[], int *index) {
    if (n / 10)
        helper(n / 10, s, index);
    s[(*index)++] = n % 10 + '0';
}
int main() {
    char str[20];
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    itoa_recursive(num, str);
    printf("String = %s\n", str);
    return 0;
}

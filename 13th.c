#include <stdio.h>
#include <string.h>
void reverse(char s[]);
void reverse_recursive(char s[], int i, int j);
void reverse(char s[]) {
    reverse_recursive(s, 0, strlen(s) - 1);
}
void reverse_recursive(char s[], int i, int j) {
    if (i >= j)
        return;
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    reverse_recursive(s, i + 1, j - 1);
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverse(str);
    printf("Reversed: %s\n", str);
    return 0;
}

#include <stdio.h>
int htoi(char s[]) {
    int i = 0, n = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;
    for (; s[i] != '\0'; i++) {
        int value;
        if (s[i] >= '0' && s[i] <= '9')
            value = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            value = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            value = s[i] - 'A' + 10;
        else
            break;  
        n = 16 * n + value;
    }
    return n;
}
int main() {
    char h1[] = "0x9F45";
    char h2[] = "FF";
    char h3[] = "0Xabd";
    printf("%s = %d\n", h1, htoi(h1));
    printf("%s = %d\n", h2, htoi(h2));
    printf("%s = %d\n", h3, htoi(h3));
    return 0;
}

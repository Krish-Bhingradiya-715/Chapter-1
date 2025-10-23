#include <stdio.h>
void escape(char s[], const char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\b':
                s[j++] = '\\';
                s[j++] = 'b';
                break;
            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
                break;
            case '\f':
                s[j++] = '\\';
                s[j++] = 'f';
                break;
            case '\v':
                s[j++] = '\\';
                s[j++] = 'v';
                break;
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                break;
            default:
                s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';
}
void unescape(char s[], const char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\\') {
            i++;
            switch (t[i]) {
                case 'n': s[j++] = '\n'; break;
                case 't': s[j++] = '\t'; break;
                case 'b': s[j++] = '\b'; break;
                case 'r': s[j++] = '\r'; break;
                case 'f': s[j++] = '\f'; break;
                case 'v': s[j++] = '\v'; break;
                case '\\': s[j++] = '\\'; break;
                default:
                    s[j++] = '\\';  
                    s[j++] = t[i];
            }
        } else {
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';
}
int main() {
    char original[] = "Hello\tWorld!\nThis is a crusial world.\b";
    char escaped[100], unescaped[100];
    escape(escaped, original);
    printf("Escaped: %s\n", escaped);
    unescape(unescaped, escaped);
    printf("Unescaped: %s\n", unescaped);
    return 0;
}

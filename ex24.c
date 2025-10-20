#include <stdio.h>
int main() {
    int c;
    int par = 0, brace = 0, bracket = 0;
    int in_comment = 0, in_quote = 0, in_char = 0;
    while ((c = getchar()) != EOF) {
        if (in_comment) {
            int d = getchar();
            if (c == '*' && d == '/') in_comment = 0;
            else if (d != EOF) ungetc(d, stdin);
        } else if (in_quote) {
            if (c == '"') in_quote = 0;
        } else if (in_char) {
            if (c == '\'') in_char = 0;
        } else {
            if (c == '/' && (c = getchar()) == '*') in_comment = 1;
            else {
                if (c == '(') par++;
                else if (c == ')') par--;
                else if (c == '{') brace++;
                else if (c == '}') brace--;
                else if (c == '[') bracket++;
                else if (c == ']') bracket--;
                else if (c == '"') in_quote = 1;
                else if (c == '\'') in_char = 1;
            }
        }
    }
    if (par != 0) printf("Unmatched parentheses\n");
    if (brace != 0) printf("Unmatched braces\n");
    if (bracket != 0) printf("Unmatched brackets\n");

return 0;
}

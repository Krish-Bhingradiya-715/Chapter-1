#include <stdio.h>
#include <ctype.h>
#include <math.h>
double atof(char s[]) {
    double val = 0.0, power = 1.0;
    int i = 0, sign = 1;
    while (isspace(s[i])) i++;
    if (s[i] == '-') sign = -1;
    if (s[i] == '+' || s[i] == '-') i++;
    while (isdigit(s[i])) {
        val = 10.0 * val + (s[i] - '0');
        i++;
    }
    if (s[i] == '.') i++;
    while (isdigit(s[i])) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
        i++;
    }
    val = sign * val / power;
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        int expSign = 1, exp = 0;
        if (s[i] == '-') { expSign = -1; i++; }
        else if (s[i] == '+') { i++; }
        while (isdigit(s[i])) {
            exp = 10 * exp + (s[i] - '0');
            i++;
        }
        val *= pow(10, expSign * exp);
    }
    return val;
}
int main() {
    char str1[] = "3.24e2";
    char str2[] = "-11.5E-3";

    printf("%s -> %g\n", str1, atof(str1)); 
    printf("%s -> %g\n", str2, atof(str2)); 
    return 0;
}

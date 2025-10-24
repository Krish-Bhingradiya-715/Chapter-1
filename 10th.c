#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAXLINE 100
#define MAXVAL 100
#define NUMBER '0'
int getop(char s[], char line[], int *pos);
void push(double f);
double pop(void);
double val[MAXVAL];
int sp = 0; 
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full\n");
}
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
int getop(char s[], char line[], int *pos) {
    int i = 0, c;
    while ((c = line[*pos]) == ' ' || c == '\t')
        (*pos)++;
    if (c == '\0')
        return EOF;
    if (!isdigit(c) && c != '.' && c != '-')
        return line[(*pos)++]; 
    if (c == '-') {
        if (isdigit(line[*pos + 1]) || line[*pos + 1] == '.')
            s[i++] = c; 
        else
            return line[(*pos)++];
        (*pos)++;
    }
    if (isdigit(c) || c == '.') {
        s[i++] = c;
        (*pos)++;
        while (isdigit(line[*pos]) || line[*pos] == '.')
            s[i++] = line[(*pos)++];
    }
    s[i] = '\0';
    return NUMBER;
}
int main() {
    char line[MAXLINE], s[MAXLINE];
    int type, pos;
    double op2;
    printf("Reverse Polish Calculator (Ctrl+D to exit)\n");
    while (fgets(line, MAXLINE, stdin) != NULL) {
        pos = 0;
        while ((type = getop(s, line, &pos)) != EOF) {
            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case '\n':
                case '=':
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }
        }
    }
    return 0;
}

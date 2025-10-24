#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXVAL 100
#define NUMBER '0'
int sp = 0;
double val[MAXVAL];
void push(double f) {
    if(sp < MAXVAL) val[sp++] = f;
    else printf("error: stack full\n");
}
double pop(void) {
    if(sp > 0) return val[--sp];
    else { printf("error: stack empty\n"); return 0.0; }
}
int getop(char s[]) {
    int i = 0, c;
    while((s[0] = c = getchar()) == ' ' || c == '\t') ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-') return c;
    if(c == '-') { 
        if(isdigit(c = getchar())) s[i++] = '-';
        else { ungetc(c, stdin); return '-'; }
    }
    if(isdigit(c)) while(isdigit(s[i++] = c = getchar()));
    if(c == '.') while(isdigit(s[i++] = c = getchar()));
    s[i-1] = '\0';
    if(c != EOF) ungetc(c, stdin);
    return NUMBER;
}
int main() {
    int type;
    double op2;
    char s[100];
    while((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER: push(atof(s)); break;
            case '+': push(pop() + pop()); break;
            case '*': push(pop() * pop()); break;
            case '-': op2 = pop(); push(pop() - op2); break;
            case '/': op2 = pop(); if(op2 != 0) push(pop() / op2); else printf("zero divisor\n"); break;
            case '%': op2 = pop(); if(op2 != 0) push((int)pop() % (int)op2); else printf("zero divisor\n"); break;
            case '\n': printf("\t%.8g\n", pop()); break;
            default: printf("Unknown command\n"); break;
        }
    }
    return 0;
}

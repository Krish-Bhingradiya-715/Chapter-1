#include <stdio.h>

int main() {
    double vars[26] = {0};  // A-Z
    char cmd;
    char var;
    double val;

    while(1) {
        printf("\nCommands:\n");
        printf("s : store value to variable\n");
        printf("r : read variable\n");
        printf("q : quit\n");
        printf("Enter command: ");
        scanf(" %c", &cmd);

        if(cmd == 'q') break;

        switch(cmd) {
            case 's':
                printf("Enter variable (A-Z): ");
                scanf(" %c", &var);
                printf("Enter value: ");
                scanf("%lf", &val);
                vars[var - 'A'] = val;
                printf("Stored %.2lf in %c\n", val, var);
                break;
            case 'r':
                printf("Enter variable (A-Z): ");
                scanf(" %c", &var);
                printf("Value of %c = %.2lf\n", var, vars[var - 'A']);
                break;
            default:
                printf("Invalid command\n");
        }
    }
    return 0;
}

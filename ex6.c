#include <stdio.h>
int main()
{
    int c;
    printf("press Enter (Ctrl+D to send EOF):\n");
    while (1) {
        c = getchar();
        printf("Value is  %d\n", (c != EOF));
        if (c == EOF)
            break;
    }
    return 0;
}

#include <stdio.h>
int main()
{
    int c;
    printf("Enter a character, then press Enter (Ctrl+D to send EOF):\n");
    while (1) {
        c = getchar();
        printf("Value of expression (getchar() != EOF): %d\n", (c != EOF));
        if (c == EOF)
            break;
    }
    return 0;
}

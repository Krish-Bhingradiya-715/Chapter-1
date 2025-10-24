#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double x, y;
    while(1) {
        printf("\n1: sin(x) 2: exp(x) 3: x^y 0: Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter x (in radians): ");
                scanf("%lf", &x);
                printf("sin(%.2lf) = %.4lf\n", x, sin(x));
                break;
            case 2:
                printf("Enter x: ");
                scanf("%lf", &x);
                printf("exp(%.2lf) = %.4lf\n", x, exp(x));
                break;
            case 3:
                printf("Enter x and y: ");
                scanf("%lf %lf", &x, &y);
                printf("%.2lf ^ %.2lf = %.4lf\n", x, y, pow(x, y));
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

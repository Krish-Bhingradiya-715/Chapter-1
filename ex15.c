#include <stdio.h>
float fahrenheit_to_celsius(float fahr);
int main() {
    float fahr;
    float lower, upper, step;
    lower = 0;    
    upper = 300; 
    step = 20;   
    printf("Fahrenheit  Celsius Table \n");
    for (fahr = lower; fahr <= upper; fahr += step) {
        printf("%10.0f %7.1f\n", fahr, fahrenheit_to_celsius(fahr));
    }
    return 0;
}
float fahrenheit_to_celsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

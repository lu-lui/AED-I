/*You are given a non-negative floating point number rounded to two decimal places celsius, that denotes the temperature in Celsius. You should convert Celsius into Kelvin and Fahrenheit and return it as an array ans = [kelvin, fahrenheit]. Return the array ans. Answers within 10-5 of the actual answer will be accepted.

Note that:
Kelvin = Celsius + 273.15
Fahrenheit = Celsius * 1.80 + 32.00*/

#include <stdio.h>
#include <stdlib.h>

double* convertTemperature(double celsius, int* returnSize);

int main() {
    double celsius, *result;
    int returnSize;

    printf("Digite a temperatura em Celsius: ");
    scanf("%lf", &celsius);

    result = convertTemperature(celsius, &returnSize);

    printf("A temperatura %lf é em Kelvin e Fahrenheit, respectivamente: \n");
    for(int i = 0; i < 2; i++)
        printf("%.5lf\n", result[i]);

    free(result);

    return 0;
}

double* convertTemperature(double celsius, int* returnSize) {
    *returnSize = 2;

    double *result = (double *)malloc(2 * sizeof(double));

    result[0] = celsius + 273.15;    
    result[1] = celsius * 1.80 + 32.0; 

    return result;
}


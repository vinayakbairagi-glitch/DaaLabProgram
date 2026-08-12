#include <stdio.h>
#include <math.h>
int main() {
    int a, r, n;
    double sum;
    printf("Enter first term, common ratio and number of terms: ");
    scanf("%d %d %d", &a, &r, &n);
    if(r == 1)
        sum = a * n;
    else
        sum = a * (pow(r, n) - 1) / (r - 1);
    printf("Sum of GP = %.2lf", sum);
    return 0;
}
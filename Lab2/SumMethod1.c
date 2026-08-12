#include <stdio.h>
#include <math.h>
int main() {
    int a, r, n;
    double sum = 0, term;
    printf("Enter first term, common ratio and number of terms: ");
    scanf("%d %d %d", &a, &r, &n);
    term = a;
    for(int i = 0; i < n; i++) {
        sum += term;
        term *= r;
    }
    printf("Sum of GP = %.2lf", sum);
    return 0;
}

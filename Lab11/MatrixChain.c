#include <stdio.h>
#include <limits.h>
#define MAX 100
void printOrder(int split[MAX][MAX], int i, int j);
int main() {
    int n, i, j, k, L;
    int p[MAX];
    int m[MAX][MAX];
    int split[MAX][MAX];
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    if (n <= 0 || n >= MAX) {
        printf("Invalid number of matrices!\n");
        return 1;
    }
    printf("Enter dimensions array:\n");
    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++) {
                int cost = m[i][k] +
                           m[k + 1][j] +
                           p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }
    printf("\nMinimum number of scalar multiplications = %d\n",
           m[1][n]);
    printf("\nOptimal Parenthesization: ");
    printOrder(split, 1, n);
    printf("\n");
    return 0;
}
void printOrder(int split[MAX][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    printOrder(split, i, split[i][j]);
    printOrder(split, split[i][j] + 1, j);
    printf(")");
}
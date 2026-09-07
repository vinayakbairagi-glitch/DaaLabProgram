#include <stdio.h>
#define MAX 64
void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int C[MAX][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void strassen(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n) {
    int i, j;
    int mid;
    int A11[MAX][MAX], A12[MAX][MAX];
    int A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX];
    int B21[MAX][MAX], B22[MAX][MAX];
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX];
    int M4[MAX][MAX], M5[MAX][MAX], M6[MAX][MAX];
    int M7[MAX][MAX];
    int T1[MAX][MAX], T2[MAX][MAX];
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    mid = n / 2;
    for (i = 0; i < mid; i++) {
        for (j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }
    addMatrix(A11, A22, T1, mid);
    addMatrix(B11, B22, T2, mid);
    strassen(T1, T2, M1, mid);
    addMatrix(A21, A22, T1, mid);
    strassen(T1, B11, M2, mid);
    subtractMatrix(B12, B22, T1, mid);
    strassen(A11, T1, M3, mid);
    subtractMatrix(B21, B11, T1, mid);
    strassen(A22, T1, M4, mid);
    addMatrix(A11, A12, T1, mid);
    strassen(T1, B22, M5, mid);
    subtractMatrix(A21, A11, T1, mid);
    addMatrix(B11, B12, T2, mid);
    strassen(T1, T2, M6, mid);
    subtractMatrix(A12, A22, T1, mid);
    addMatrix(B21, B22, T2, mid);
    strassen(T1, T2, M7, mid);
    addMatrix(M1, M4, T1, mid);
    subtractMatrix(T1, M5, T2, mid);
    addMatrix(T2, M7, C, mid);
    addMatrix(M3, M5, T1, mid);
    addMatrix(M2, M4, T2, mid);
    subtractMatrix(M1, M2, T2, mid);
    addMatrix(T2, M3, T2, mid);
    addMatrix(T2, M6, T2, mid);
    for (i = 0; i < mid; i++) {
        for (j = 0; j < mid; j++) {
            C[i][j] = T1[i][j];
            C[i][j + mid] = M3[i][j] + M5[i][j];
            C[i + mid][j] = M2[i][j] + M4[i][j];
            C[i + mid][j + mid] = T2[i][j];
        }
    }
}
int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n, i, j;
    printf("Enter order of square matrices: ");
    scanf("%d", &n);
    printf("Enter elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    strassen(A, B, C, n);
    printf("Resultant matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
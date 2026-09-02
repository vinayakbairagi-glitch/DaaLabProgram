#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void insertionSort(int bucket[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = bucket[i];
        j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}
void bucketSort(int arr[], int n) {
    int buckets[MAX][MAX];
    int count[MAX] = {0};
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    for (int i = 0; i < n; i++) {
        int index = (arr[i] * n) / (max + 1);
        buckets[index][count[index]] = arr[i];
        count[index]++;
    }
    for (int i = 0; i < n; i++)
        insertionSort(buckets[i], count[i]);
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter non-negative elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
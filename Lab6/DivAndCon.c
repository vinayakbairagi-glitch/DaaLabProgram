#include <stdio.h>
struct Result {
    int min;
    int max;
};
struct Result findMinMax(int arr[], int low, int high) {
    struct Result result, left, right;
    int mid;
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }
    mid = low + (high - low) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;
    return result;
}
int main() {
    int n, i;
    struct Result result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    result = findMinMax(arr, 0, n - 1);
    printf("Minimum element = %d\n", result.min);
    printf("Maximum element = %d\n", result.max);
    return 0;
}
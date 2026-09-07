#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int maxCrossingSum(int arr[], int low, int mid, int high) {
    int leftSum = -1000000000;
    int rightSum = -1000000000;
    int sum = 0;
    int i;
    for (i = mid; i >= low; i--) {
        sum = sum + arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    sum = 0;
    for (i = mid + 1; i <= high; i++) {
        sum = sum + arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}
int maxSubarraySum(int arr[], int low, int high) {
    int mid;
    int leftSum, rightSum, crossSum;
    if (low == high) {
        return arr[low];
    }
    mid = low + (high - low) / 2;
    leftSum = maxSubarraySum(arr, low, mid);
    rightSum = maxSubarraySum(arr, mid + 1, high);
    crossSum = maxCrossingSum(arr, low, mid, high);
    return max(max(leftSum, rightSum), crossSum);
}
int main() {
    int n, i, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    result = maxSubarraySum(arr, 0, n - 1);
    printf("Maximum subarray sum = %d\n", result);
    return 0;
}
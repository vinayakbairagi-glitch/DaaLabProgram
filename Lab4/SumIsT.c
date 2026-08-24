#include <stdio.h>
#define SIZE 101
int hashTable[SIZE];
int hashFunction(int key) {
    if (key < 0)
        key = -key;
    return key % SIZE;
}
void insert(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return;
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}
int search(int key) {
    int index = hashFunction(key);
    int start = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return 1;
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }
    return 0;
}
int main() {
    int n, T;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter target value: ");
    scanf("%d", &T);
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    for (int i = 0; i < n; i++) {
        int complement = T - arr[i];
        if (search(complement)) {
            printf("Pair found: %d + %d = %d\n",
                   complement, arr[i], T);
            return 0;
        }
        insert(arr[i]);
    }
    printf("No pair found\n");
    return 0;
}
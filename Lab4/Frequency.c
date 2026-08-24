#include <stdio.h>
#define SIZE 101
struct Entry {
    int value;
    int frequency;
    int occupied;
};
struct Entry table[SIZE];
int hashFunction(int value) {
    if (value < 0)
        value = -value;
    return value % SIZE;
}
void insertOrUpdate(int value) {
    int index = hashFunction(value);
    while (table[index].occupied &&
           table[index].value != value) {
        index = (index + 1) % SIZE;
    }
    if (table[index].occupied) {
        table[index].frequency++;
    }
    else {
        table[index].value = value;
        table[index].frequency = 1;
        table[index].occupied = 1;
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < SIZE; i++) {
        table[i].occupied = 0;
        table[i].frequency = 0;
    }
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        insertOrUpdate(arr[i]);
    }
    printf("\nFrequency of elements:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i].occupied) {
            printf("%d : %d\n",
                   table[i].value,
                   table[i].frequency);
        }
    }
    return 0;
}
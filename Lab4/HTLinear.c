#include <stdio.h>
#define SIZE 10
int main() {
    int hashTable[SIZE];
    int n, key, index;
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    if (n > SIZE) {
        printf("Hash table is full.\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        index = key % SIZE;
        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }
        hashTable[index] = key;
    }
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("%d : EMPTY\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
    return 0;
}
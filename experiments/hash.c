#include <stdio.h>
#define SIZE 10  
void insert(int hashTable[], int key) {
    int index = key % SIZE;  
    int originalIndex = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == originalIndex) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}
void display(int hashTable[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}
int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
    int n;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    int keys[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
        insert(hashTable, keys[i]);
    }
    display(hashTable);
    return 0;
}

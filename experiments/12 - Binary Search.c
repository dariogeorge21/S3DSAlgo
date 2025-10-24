#include <stdio.h>
int binarySearch(int arr[], int n, int target, int *comparisons) {
    int low = 0, high = n - 1, mid;
    *comparisons = 0;
    while (low <= high) {
        (*comparisons)++;
        mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;}
    return -1;}
int main() {
    int n, target, i, comparisons;
    printf("Enter size of sorted array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &target);
    int index = binarySearch(arr, n, target, &comparisons);
    if (index != -1)
        printf("Element %d found at index %d\n", target, index);
    else
        printf("Element %d not found\n", target);

    int space_main = sizeof(n) + sizeof(target) + sizeof(i) + sizeof(comparisons) + sizeof(arr);
    int space_function = sizeof(int) * 3;
    int total_space = space_main + space_function;
    printf("\n Time Complexity: %d\n", comparisons);
    printf("Space Complexity: %d bytes\n", total_space);
    return 0;
}

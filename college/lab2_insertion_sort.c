#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key, comparisonCount = 0, swapCount = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisonCount++;
            arr[j + 1] = arr[j];
            j--;
            swapCount++;
        }
        comparisonCount++;
        arr[j + 1] = key;
        if (j + 1 != i) swapCount++;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of comparisons: %d\n", comparisonCount);
    printf("Number of swaps: %d\n", swapCount);
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    return 0;
}
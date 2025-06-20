// Following incremental approach implement the selection sort algorithm using function in C
// programming language.
// * Analyze the code for Time and Space Complexity as shown in the introductory lab session.
// * Prepare lab report as per the sample report provided in the introductory lab session


#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    int comparisonCount = 0, swapCount = 0;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparisonCount++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swapCount++;
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    return 0;
}



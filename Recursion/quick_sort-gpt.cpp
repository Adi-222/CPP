#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int split(int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0;

    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;
    while (i <= pivotIndex && j >= pivotIndex) {
        while (arr[i] <= arr[pivotIndex]) {
            i++;
        }

        while (arr[j] > arr[pivotIndex]) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quicksort(int arr[], int s, int e) {
    if (s >= e) {
        return;
    }
    int p;
    p = split(arr, s, e);

    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main() {
    int arr[6] = {2, 4, 1, 6, 3, 8};
    int n = 6;

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

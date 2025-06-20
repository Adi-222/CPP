#include<iostream>
using namespace std;

void selectionsort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int miniindex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[miniindex]) {
                miniindex = j;
            }
        }
        int temp = arr[miniindex];
        arr[miniindex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionsort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

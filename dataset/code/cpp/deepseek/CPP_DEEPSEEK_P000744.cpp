#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    if (n == 1)
        return;

    int minIndex = n - 1;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[minIndex])
            minIndex = i;
    }

    swap(arr[n - 1], arr[minIndex]);

    selectionSort(arr, n - 1);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    selectionSort(arr, n);

    cout << "After Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
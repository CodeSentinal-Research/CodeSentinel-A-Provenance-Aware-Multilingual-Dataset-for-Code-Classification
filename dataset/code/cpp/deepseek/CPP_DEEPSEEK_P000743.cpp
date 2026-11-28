#include <iostream>
using namespace std;

void recursiveBubbleSort(int arr[], int n) {
    if (n == 1)
        return;

    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }

    recursiveBubbleSort(arr, n-1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    recursiveBubbleSort(arr, n);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
This C++ code first reads the size of the array from the user. Then, it reads the array elements from the user. The `recursiveBubbleSort` function then sorts the array using the bubble sort algorithm implemented recursively. The sorted array is printed to the console.
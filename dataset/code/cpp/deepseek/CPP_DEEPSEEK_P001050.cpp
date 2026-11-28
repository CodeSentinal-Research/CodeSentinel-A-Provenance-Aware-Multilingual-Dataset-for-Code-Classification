Here is the C++ code for building a Min Heap from an unsorted array:

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] < arr[smallest])
        smallest = leftChild;

    if (rightChild < n && arr[rightChild] < arr[smallest])
        smallest = rightChild;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    buildHeap(arr, n);

    cout << "Min Heap: ";
    printHeap(arr, n);

    return 0;
}

In this code, the `heapify` function is used to maintain the heap property at all times. The `buildHeap` function constructs the Min Heap by calling `heapify` on all non-leaf nodes starting from the last non-leaf node (which is `n/2 - 1`). The `printHeap` function is used to print the Min Heap.
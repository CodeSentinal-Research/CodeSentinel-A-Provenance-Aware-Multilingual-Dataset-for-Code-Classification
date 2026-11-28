Here is the C++ code to rearrange an array into a Max Heap.

#include <iostream>
#include <algorithm>
using namespace std;

void maxHeapify(int arr[], int i, int n){
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != i){
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, n);
    }
}

void buildMaxHeap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, i, n);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    buildMaxHeap(arr, n);

    cout << "The rearranged Max Heap is: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

This code first reads the size of the array `n`. Then it reads the array `arr[]`. After that, it builds a Max Heap from the array using the `buildMaxHeap` function. Finally, it prints the rearranged Max Heap using the `maxHeapify` function.
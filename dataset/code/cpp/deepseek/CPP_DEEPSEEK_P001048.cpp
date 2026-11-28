Here is a C++ code snippet to solve the problem:

#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int idx, int size) {
    int largest = idx;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    if (leftChild < size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != idx) {
        swap(arr[idx], arr[largest]);
        heapify(arr, largest, size);
    }
}

void printHeap(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int idx;
    cin >> idx;
    --idx;

    heapify(arr, idx, size);

    printHeap(arr);

    return 0;
}

This code first reads the size of the array and then the array itself. After that, it reads the index of the subtree to be heapified. The `heapify` function recursively checks and swaps the subtree with the largest child until the heap property is restored. The `printHeap` function prints the heap.
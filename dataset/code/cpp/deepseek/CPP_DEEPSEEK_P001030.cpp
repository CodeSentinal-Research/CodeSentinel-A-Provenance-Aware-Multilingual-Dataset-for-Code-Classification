#include <iostream>
using namespace std;

void minHeapify(int arr[], int i, int n) {
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] < arr[smallest])
        smallest = leftChild;

    if (rightChild < n && arr[rightChild] < arr[smallest])
        smallest = rightChild;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, smallest, n);
    }
}

void buildMinHeap(int arr[], int n) {
    int startIdx = (n / 2) - 1; 

    for (int i = startIdx; i >= 0; i--) {
        minHeapify(arr, i, n);
    }
}

void printArray(int arr[], int n) {
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

    buildMinHeap(arr, n);

    printArray(arr, n);

    return 0;
}
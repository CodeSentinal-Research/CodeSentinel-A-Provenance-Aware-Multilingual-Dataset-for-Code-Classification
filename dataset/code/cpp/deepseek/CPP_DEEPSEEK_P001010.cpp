Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(vector<int>& arr, int i, int n) {
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        printArray(arr);
        heapify(arr, largest, n);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }

    printArray(arr);

    return 0;
}
This code first reads the number of elements in the array and then the array itself. It then constructs a Max Heap using the given array and prints it.
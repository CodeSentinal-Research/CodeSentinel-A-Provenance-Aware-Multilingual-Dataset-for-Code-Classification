#include <iostream>
using namespace std;

void printHeap(int *heap, int n) {
    for (int i = 1; i <= n; i++) {
        cout << heap[i] << " ";
    }
    cout << "\n";
}

void heapify(int *heap, int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right <= n && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        printHeap(heap, n);
        heapify(heap, n, largest);
    }
}

void increaseKey(int *heap, int n, int i, int newValue) {
    if (newValue < heap[i]) {
        cout << "New key is smaller than current key\n";
        return;
    }

    heap[i] = newValue;

    while (i > 1 && heap[i/2] < heap[i]) {
        swap(heap[i], heap[i/2]);
        i = i/2;
    }

    printHeap(heap, n);
}

int main() {
    int n;
    cin >> n;

    int *heap = new int[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> heap[i];
    }

    int i, newValue;
    cin >> i >> newValue;

    increaseKey(heap, n, i, newValue);

    delete [] heap;
    return 0;
}
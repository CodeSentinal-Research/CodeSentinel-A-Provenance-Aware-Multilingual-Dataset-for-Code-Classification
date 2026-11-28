Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_heap(const vector<int>& heap) {
    for (int i : heap) {
        cout << i << ' ';
    }
    cout << '\n';
}

void max_heapify(vector<int>& heap, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        max_heapify(heap, largest);
    }
}

void replace_root(vector<int>& heap, int new_value) {
    heap[0] = new_value;
    for (int i = heap.size() / 2 - 1; i >= 0; --i) {
        max_heapify(heap, i);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> heap(n);
    for (int& i : heap) {
        cin >> i;
    }
    int replacement;
    cin >> replacement;

    for (int& i : heap) {
        i = -1 * i;
    }

    replace_root(heap, replacement);

    print_heap(heap);

    for (int& i : heap) {
        i = 1 * i;
    }

    return 0;
}

This program first reads the heap from the input, then replaces the root with the new value, restores the max heap property, and prints the updated heap.
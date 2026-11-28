// 4. Find K Smallest Elements (Manual Min Heap)
// Language Used: C++
#include <iostream>
using namespace std;
class MinHeap {
    int *heapArray, maxCapacity, currentSize;

    int getParent(int index) { return (index - 1) / 2; }
    int getLeftChild(int index) { return 2 * index + 1; }
    int getRightChild(int index) { return 2 * index + 2; }

    void heapifyUp(int index) {
        while (index && heapArray[getParent(index)] > heapArray[index]) {
            swap(heapArray[index], heapArray[getParent(index)]);
            index = getParent(index);
        }
    }
    void heapifyDown(int index) {
        int smallest = index;
        int left = getLeftChild(index), right = getRightChild(index);
        if (left < currentSize && heapArray[left] < heapArray[smallest]) smallest = left;
        if (right < currentSize && heapArray[right] < heapArray[smallest]) smallest = right;
        if (smallest != index) {
            swap(heapArray[index], heapArray[smallest]);
            heapifyDown(smallest);
        }
    }
public:
    MinHeap(int capacity) {
        maxCapacity = capacity;
        currentSize = 0;
        heapArray = new int[capacity];
    }
    void insert(int value) {
        heapArray[currentSize] = value;
        heapifyUp(currentSize);
        currentSize++;
    }
    int extractMin() {
        int rootValue = heapArray[0];
        heapArray[0] = heapArray[--currentSize];
        heapifyDown(0);
        return rootValue;
    }
    ~MinHeap() {
        delete[] heapArray;
    }
};
int main() {
    int totalItems, k;
    cin >> totalItems >> k;
    if (totalItems < 1 || totalItems > 100000 || k < 1 || k > totalItems)
        return cout << "Invalid input\n", 0;

    MinHeap heap(totalItems);
    for (int i = 0, price; i < totalItems; i++) {
        cin >> price;
        heap.insert(price);
    }

    for (int i = 0; i < k; i++)
        cout << heap.extractMin() << " ";
    cout << "\n";
}
/*
Approach:
We manually implemented a Min Heap using an array.
Insert all prices, then extract the smallest element k times.
Each heap operation takes O(log n), so total complexity is O(n log n).
No STL heap functions were used.
*/

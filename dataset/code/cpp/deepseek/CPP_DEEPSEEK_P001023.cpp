Here is the C++ code that implements the given problem:

#include <iostream>
#include <vector>

using namespace std;

int findParent(vector<int> &heap, int node) {
    if (node == 0) {
        return -1;
    }

    return heap[node / 2];
}

int main() {
    int N;
    cin >> N;

    vector<int> heap(N);
    for (int i = 0; i < N; i++) {
        cin >> heap[i];
    }

    int node;
    cin >> node;

    cout << findParent(heap, node) << endl;

    return 0;
}
This code defines a function `findParent` that takes a heap and a node index as input, and returns the parent of the given node. If the node is the root (index 0), the parent is not defined, so the function returns -1. Otherwise, the parent is found by dividing the node index by 2 and accessing the parent in the heap.

In the main function, the program reads the size of the heap and the heap itself, and the index of the node to find the parent of. The parent of the given node is then printed to the console.
Here is the C++ code for the given problem. The code uses the STL priority_queue which is a min heap. The elements in a min heap are arranged in such a way that the parent node is always smaller than or equal to its child node.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void merge(priority_queue<int, vector<int>, greater<int>>& minHeap1, priority_queue<int, vector<int>, greater<int>>& minHeap2) {
    while (!minHeap2.empty()) {
        minHeap1.push(minHeap2.top());
        minHeap2.pop();
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<int, vector<int>, greater<int>> minHeap1;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        minHeap1.push(num);
    }

    priority_queue<int, vector<int>, greater<int>> minHeap2;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        minHeap2.push(num);
    }

    merge(minHeap1, minHeap2);

    while (!minHeap1.empty()) {
        cout << minHeap1.top() << " ";
        minHeap1.pop();
    }

    return 0;
}

In this code, the priority_queue is a min heap. The `merge` function first pushes all elements from the second min heap to the first min heap, then it pops all elements from the first min heap. This process is repeated until all elements from the second min heap are pushed to the first min heap. The merged heap is then printed out.

The input to the program is the size of the first and second min heap, followed by the elements of the first min heap, followed by the elements of the second min heap. The elements are assumed to be distinct and in sorted order.
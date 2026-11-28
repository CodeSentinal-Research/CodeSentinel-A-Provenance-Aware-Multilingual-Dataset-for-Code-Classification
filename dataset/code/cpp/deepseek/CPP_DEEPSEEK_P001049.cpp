#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        pq.push(val);
    }

    for (int i = 0; i < Q; i++) {
        int index, newVal;
        cin >> index >> newVal;
        pq[index - 1] = newVal;
        
        int child = index - 1;
        while (child > 0 && pq[child] > pq[parent(child)]) {
            swap(pq[child], pq[parent(child)]);
            child = parent(child);
        }
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
This C++ code reads the number of elements N and the number of update operations Q, then it reads N elements and pushes them into a priority_queue. After that, it executes Q update operations where it reads an index and a new value, then replaces the key at the given index with the new value. It then restores the heap property by swapping and heapifying the parent and child nodes if the updated key is greater than its parent. Finally, it prints the final heap.
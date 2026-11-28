Here's the code:

#include <iostream>
#include <queue>
using namespace std;

int countNodesGreaterThanRoot(priority_queue<int>& maxHeap) {
    int count = 0;
    while (!maxHeap.empty()) {
        int node = maxHeap.top();
        maxHeap.pop();
        if (node > maxHeap.top()) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        maxHeap.push(val);
    }
    cout << countNodesGreaterThanRoot(maxHeap) << endl;
    return 0;
}

This program reads the number of nodes and values from the standard input, builds a max heap from those values, and then counts the nodes in the heap that are greater than the root.

Please note that this solution assumes that you want to count nodes that are greater than their children. If you want to count nodes that are greater than their parent, you will need to adjust the `if (node > maxHeap.top())` line in the `countNodesGreaterThanRoot` function.
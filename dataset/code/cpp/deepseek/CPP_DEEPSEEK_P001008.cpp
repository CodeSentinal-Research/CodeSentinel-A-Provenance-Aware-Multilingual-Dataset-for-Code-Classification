Here is the C++ code to solve the problem:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, val;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++) {
        cin >> val;
        minHeap.push(val);
    }

    cin >> val;
    minHeap.push(val);

    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}
This code first reads the number of elements in the heap and inserts them into the priority queue. Then it reads the value to be inserted and pushes it into the priority queue. After that, it prints the heap after every insertion.
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap; 

    while (n--) {
        int num;
        cin >> num;

        if (maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
       
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (maxHeap.size() > minHeap.size()) {
            cout << maxHeap.top() << endl;
        } else {
            cout << (maxHeap.top() + minHeap.top()) / 2.0 << endl;
        }
    }

    return 0;
}

In this solution, we use two heaps to maintain the numbers in the stream. The max heap stores the smaller half of the numbers and the min heap stores the larger half. In the end, the median is the root of the max heap.
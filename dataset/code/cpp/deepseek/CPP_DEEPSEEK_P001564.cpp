Here is the C++ code:

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

double getMedian(priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap) {
    if (maxHeap.size() == minHeap.size())
        return (maxHeap.top() + minHeap.top()) / 2.0;
    else
        return maxHeap.top();
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N; i++) {
        maxHeap.push(nums[i]);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (i >= K - 1) {
            cout << getMedian(maxHeap, minHeap) << " ";
            if (i == K - 1) {
                cout << endl;
                continue;
            }

            int out = nums[i - K + 1];
            if (&out == &(maxHeap.top()))
                maxHeap.pop();
            else {
                minHeap.pop();
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    return 0;
}
In this code, we use two priority queues - a max heap to keep the numbers in the current window and a min heap to keep the larger half of the numbers. The top of the max heap is the current median, and the top of the min heap is the next number to be inserted. We continuously insert the new number into the max heap and then rebalance it, until we've inserted K numbers into the window.
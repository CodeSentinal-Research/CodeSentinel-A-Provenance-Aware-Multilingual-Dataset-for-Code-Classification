Here is the C++ code:

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

vector<int> topKFrequent(int nums[], int size, int k) {
    unordered_map<int, int> freqMap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < size; i++) {
        freqMap[nums[i]]++;
    }

    for (auto i : freqMap) {
        pq.push(make_pair(i.second, i.first));
        if (pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 2, 2, 3, 1, 4, 5, 5, 5, 4};
    int size = sizeof(nums) / sizeof(int);
    int k = 2;

    vector<int> result = topKFrequent(nums, size, k);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

This code first constructs an unordered map to count the frequency of each number in the input array. Then, it constructs a max heap from the frequency map. The max heap is a complete binary tree where the value at each node is greater than or equal to the values at its children.

In this code, we pop the highest frequency element from the max heap and push the next highest frequency element into the max heap. This process continues until the max heap size is less than the input k. The remaining elements in the max heap are the top k frequent elements.
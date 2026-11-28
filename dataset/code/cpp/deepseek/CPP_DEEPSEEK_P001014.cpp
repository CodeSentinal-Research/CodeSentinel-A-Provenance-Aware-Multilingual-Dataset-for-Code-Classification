Here is the C++ code for the given problem:

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
};

void mergeSortedArrays(int k, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            minHeap.push({i, j});
        }
    }

    while (!minHeap.empty()) {
        pair<int, int> top = minHeap.top();
        cout << top.first << " " << top.second << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {
    int k, n;
    cin >> k >> n;
    mergeSortedArrays(k, n);
    return 0;
}

This code uses a priority queue to store pairs of integers. Each pair contains an index for the array and a position in that array. The priority queue is ordered by the first element of the pair (the value to be merged), and uses a custom comparator to ensure the pair is in the correct order. The pairs are then popped and printed in the order they were inserted.
Here is the C++ code snippet for the given problem. This solution uses a priority queue to keep track of the frequency of each barcode. It then pops the most frequent barcode and adds it to the result, then the next most frequent barcode. This process is repeated until all barcodes have been processed.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> rearrangeBarcodes(vector<int> barcodes) {
    priority_queue<pair<int, int>> pq;
    for (int b : barcodes) {
        if (!b) continue;
        pq.push({b, 1});
    }
    
    vector<int> res;
    while (pq.size() > 1) {
        pair<int, int> a = pq.top();
        pq.pop();
        pair<int, int> b = pq.top();
        pq.pop();
        res.push_back(a.first);
        res.push_back(b.first);
        if (--a.second > 1) pq.push(a);
        if (--b.second > 1) pq.push(b);
    }
    if (!pq.empty()) {
        res.push_back(pq.top().first);
    }
    return res;
}

int main() {
    vector<int> barcodes = {1, 3, 3, 2, 2};
    vector<int> res = rearrangeBarcodes(barcodes);
    for (int b : res) {
        cout << b << " ";
    }
    return 0;
}

This code creates a priority queue and pushes each barcode with its frequency into the queue. It then pops the two barcodes with the highest frequency, adds them to the result, and pushes the remaining barcodes back into the queue. This process is repeated until all barcodes have been processed. If there is a single barcode left in the queue, it is added to the result. The result is then returned.
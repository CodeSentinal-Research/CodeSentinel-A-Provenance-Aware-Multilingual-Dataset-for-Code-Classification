#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> freq(n);
    for (int i = 0; i < n; ++i) cin >> freq[i];
    
    priority_queue<int, vector<int>, greater<int>> minHeap(freq.begin(), freq.end());
    
    long long cost = 0;
    while (minHeap.size() > 1) {
        int f1 = minHeap.top(); minHeap.pop();
        int f2 = minHeap.top(); minHeap.pop();
        int sum = f1 + f2;
        cost += sum;
        minHeap.push(sum);
    }
    
    cout << cost << endl;
    return 0;
}

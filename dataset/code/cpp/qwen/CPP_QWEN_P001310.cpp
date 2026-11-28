#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sticks(n);
    for (int i = 0; i < n; ++i) cin >> sticks[i];
    
    priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());
    
    long long cost = 0;
    while (minHeap.size() > 1) {
        int s1 = minHeap.top(); minHeap.pop();
        int s2 = minHeap.top(); minHeap.pop();
        int sum = s1 + s2;
        cost += sum;
        minHeap.push(sum);
    }
    
    cout << cost << endl;
    return 0;
}

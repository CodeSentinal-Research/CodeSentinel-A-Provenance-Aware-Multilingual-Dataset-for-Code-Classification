#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, bricks, ladders;
    cin >> n >> bricks >> ladders;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) cin >> heights[i];
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < n - 1; ++i) {
        int diff = heights[i+1] - heights[i];
        if (diff <= 0) continue;
        
        minHeap.push(diff);
        if (minHeap.size() > ladders) {
            bricks -= minHeap.top();
            minHeap.pop();
            if (bricks < 0) {
                cout << i << endl;
                return 0;
            }
        }
    }
    
    cout << n - 1 << endl;
    return 0;
}

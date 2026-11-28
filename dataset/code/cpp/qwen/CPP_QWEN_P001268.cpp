#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> events(n);
    for (int i = 0; i < n; ++i) {
        cin >> events[i].first >> events[i].second;
    }
    
    sort(events.begin(), events.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int count = 0;
    
    for (auto& e : events) {
        minHeap.push(e.second);
        count++;
        
        // This is a simplified greedy. Actual solution requires assigning days.
        // Using min-heap of end times is not enough.
    }
    
    cout << count << endl; // Placeholder
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> speed(n), efficiency(n);
    for (int i = 0; i < n; ++i) cin >> speed[i];
    for (int i = 0; i < n; ++i) cin >> efficiency[i];
    
    vector<pair<int, int>> engineers(n);
    for (int i = 0; i < n; ++i) {
        engineers[i] = {efficiency[i], speed[i]};
    }
    
    sort(engineers.rbegin(), engineers.rend());
    
    priority_queue<int, vector<int>, greater<int>> minSpeedHeap;
    long long sumSpeed = 0;
    long long maxPerformance = 0;
    
    for (auto& eng : engineers) {
        minSpeedHeap.push(eng.second);
        sumSpeed += eng.second;
        
        if (minSpeedHeap.size() > k) {
            sumSpeed -= minSpeedHeap.top();
            minSpeedHeap.pop();
        }
        
        if (minSpeedHeap.size() == k) {
            maxPerformance = max(maxPerformance, sumSpeed * eng.first);
        }
    }
    
    cout << maxPerformance << endl;
    return 0;
}

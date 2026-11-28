#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, k, initialCapital;
    cin >> n >> k >> initialCapital;
    
    vector<pair<int, int>> projects(n); // {capital, profit}
    for (int i = 0; i < n; ++i) {
        cin >> projects[i].first >> projects[i].second;
    }
    
    // Sort by capital required
    sort(projects.begin(), projects.end());
    
    priority_queue<int> maxProfitHeap;
    int idx = 0;
    int capital = initialCapital;
    
    for (int i = 0; i < k; ++i) {
        while (idx < n && projects[idx].first <= capital) {
            maxProfitHeap.push(projects[idx].second);
            idx++;
        }
        
        if (maxProfitHeap.empty()) break;
        
        capital += maxProfitHeap.top();
        maxProfitHeap.pop();
    }
    
    cout << capital << endl;
    return 0;
}

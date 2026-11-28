#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> costs(2*n);
    for (int i = 0; i < 2*n; ++i) {
        cin >> costs[i].first >> costs[i].second;
    }
    
    // Sort by difference (costA - costB)
    sort(costs.begin(), costs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return (a.first - a.second) < (b.first - b.second);
    });
    
    int totalCost = 0;
    for (int i = 0; i < n; ++i) {
        totalCost += costs[i].first; // Send to A
    }
    for (int i = n; i < 2*n; ++i) {
        totalCost += costs[i].second; // Send to B
    }
    
    cout << totalCost << endl;
    return 0;
}

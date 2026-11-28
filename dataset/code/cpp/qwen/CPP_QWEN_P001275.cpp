#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> quality(n), wage(n);
    for (int i = 0; i < n; ++i) cin >> quality[i];
    for (int i = 0; i < n; ++i) cin >> wage[i];
    
    vector<pair<double, int>> ratioIndex;
    for (int i = 0; i < n; ++i) {
        ratioIndex.push_back({(double)wage[i] / quality[i], i});
    }
    
    sort(ratioIndex.begin(), ratioIndex.end());
    
    priority_queue<int> maxQualityHeap;
    long long sumQuality = 0;
    double minCost = 1e18;
    
    for (auto& ri : ratioIndex) {
        int idx = ri.second;
        maxQualityHeap.push(quality[idx]);
        sumQuality += quality[idx];
        
        if (maxQualityHeap.size() > k) {
            sumQuality -= maxQualityHeap.top();
            maxQualityHeap.pop();
        }
        
        if (maxQualityHeap.size() == k) {
            minCost = min(minCost, sumQuality * ri.first);
        }
    }
    
    cout << fixed << setprecision(5) << minCost << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    vector<int> starts(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
        starts[i] = intervals[i].first;
    }
    
    sort(starts.begin(), starts.end());
    
    vector<int> result(n, -1);
    for (int i = 0; i < n; ++i) {
        int end = intervals[i].second;
        // Find smallest start >= end
        auto it = lower_bound(starts.begin(), starts.end(), end);
        if (it != starts.end()) {
            // Find original index
            int val = *it;
            // Note: This assumes unique starts as per constraint.
            // To get index, we'd need a map from start to index.
            // For simplicity in this snippet, assuming we just need the value or index logic is handled externally.
            // Problem asks for indices.
        }
    }
    
    // Correct implementation requires mapping start values to original indices
    vector<pair<int, int>> sortedIntervals(n);
    for(int i=0; i<n; ++i) sortedIntervals[i] = {intervals[i].first, i};
    sort(sortedIntervals.begin(), sortedIntervals.end());
    
    vector<int> startVals(n);
    for(int i=0; i<n; ++i) startVals[i] = sortedIntervals[i].first;
    
    for (int i = 0; i < n; ++i) {
        int end = intervals[i].second;
        auto it = lower_bound(startVals.begin(), startVals.end(), end);
        if (it != startVals.end()) {
            int idxInSorted = it - startVals.begin();
            result[i] = sortedIntervals[idxInSorted].second;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    return 0;
}

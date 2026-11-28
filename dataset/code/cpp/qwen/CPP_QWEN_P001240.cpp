#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });
    
    int removed = 0;
    int lastEnd = intervals[0].second;
    
    for (int i = 1; i < n; ++i) {
        if (intervals[i].first < lastEnd) {
            removed++;
        } else {
            lastEnd = intervals[i].second;
        }
    }
    
    cout << removed << endl;
    return 0;
}

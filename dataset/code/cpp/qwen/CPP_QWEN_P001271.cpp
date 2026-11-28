#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ranges(n+1);
    for (int i = 0; i <= n; ++i) cin >> ranges[i];
    
    vector<pair<int, int>> intervals;
    for (int i = 0; i <= n; ++i) {
        int start = max(0, i - ranges[i]);
        int end = min(n, i + ranges[i]);
        intervals.push_back({start, end});
    }
    
    sort(intervals.begin(), intervals.end());
    
    int taps = 0;
    int currEnd = 0;
    int nextEnd = 0;
    int i = 0;
    
    while (currEnd < n) {
        while (i <= n && intervals[i].first <= currEnd) {
            nextEnd = max(nextEnd, intervals[i].second);
            i++;
        }
        
        if (nextEnd == currEnd) {
            cout << -1 << endl;
            return 0;
        }
        
        currEnd = nextEnd;
        taps++;
    }
    
    cout << taps << endl;
    return 0;
}

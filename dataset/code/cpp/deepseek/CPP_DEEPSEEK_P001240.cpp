Here is a simple solution in C++ to solve the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareInterval(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int eraseOverlappingIntervals(vector<pair<int, int>> &intervals) {
    int n = intervals.size();
    if (n == 0) {
        return 0;
    }
    sort(intervals.begin(), intervals.end(), compareInterval);
    int end = intervals[0].second;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (intervals[i].first <= end) {
            end = min(end, intervals[i].second);
        } else {
            ans++;
            end = intervals[i].second;
        }
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> intervals(N);
    for (int i = 0; i < N; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    int ans = eraseOverlappingIntervals(intervals);
    cout << ans << endl;
    return 0;
}
In this code, we first sort the intervals by the second end of interval. Then, we iterate over the sorted intervals. If the start of the current interval is less than or equal to the end of the previous interval, we update the end of the previous interval to the smaller end of the two intervals. Otherwise, we increment the count of removed intervals and update the end of the current interval to the end of the two intervals.
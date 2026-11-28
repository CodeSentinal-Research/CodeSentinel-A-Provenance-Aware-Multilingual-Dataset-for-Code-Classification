#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    for (auto& interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++) {
        int low, high;
        cin >> low >> high;
        vector<int> interval = {low, high};
        intervals.push_back(interval);
    }
    int low, high;
    cin >> low >> high;
    vector<int> newInterval = {low, high};
    vector<vector<int>> result = insert(intervals, newInterval);
    for (auto& interval : result) {
        cout << interval[0] << " " << interval[1] << "\n";
    }
    return 0;
}
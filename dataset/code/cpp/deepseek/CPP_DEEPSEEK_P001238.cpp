#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);

    vector<Interval> merged;
    for (int i = 0; i < intervals.size(); i++) {
        if (merged.empty() || merged.back().end < intervals[i].start) {
            merged.push_back(intervals[i]);
        } else {
            merged.back().end = max(merged.back().end, intervals[i].end);
        }
    }

    return merged;
}

int main() {
    int n;
    cin >> n;
    vector<Interval> intervals(n, Interval());

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    vector<Interval> result = merge(intervals);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i].start << " " << result[i].end << endl;
    }

    return 0;
}
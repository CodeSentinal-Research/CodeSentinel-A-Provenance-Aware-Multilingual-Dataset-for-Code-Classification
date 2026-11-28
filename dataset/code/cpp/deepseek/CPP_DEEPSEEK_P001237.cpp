#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> intervals(N);

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        intervals[i] = make_pair(end, start);
    }

    sort(intervals.begin(), intervals.end());

    int end = -1;
    int removed = 0;

    for (int i = 0; i < N; i++) {
        if (intervals[i].second > end) {
            end = intervals[i].first;
        } else {
            removed++;
        }
    }

    cout << removed << endl;

    return 0;
}
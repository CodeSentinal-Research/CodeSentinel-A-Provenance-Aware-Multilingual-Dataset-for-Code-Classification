#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> events(N);

    for (int i = 0; i < N; i++) {
        cin >> events[i].first >> events[i].second;
    }

    sort(events.begin(), events.end());

    int end = INT_MIN;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (events[i].first >= end) {
            cnt++;
            end = events[i].second;
        }
    }

    cout << cnt << endl;

    return 0;
}
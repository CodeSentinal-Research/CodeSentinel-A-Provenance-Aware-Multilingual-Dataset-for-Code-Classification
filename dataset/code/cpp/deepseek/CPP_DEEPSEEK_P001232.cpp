#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return (a.second < b.second);
}

int activitySelection(int start[], int finish[], int n) {
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; i++) {
        activities.push_back(make_pair(start[i], finish[i]));
    }

    sort(activities.begin(), activities.end(), compare);

    int i = 0;
    int count = 1;
    int j = 1;
    while (j < n) {
        if (activities[i].second < activities[j].first) {
            count++;
            i = j;
        }
        j++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int start[n], finish[n];
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> finish[i];
    }
    cout << activitySelection(start, finish, n);
    return 0;
}
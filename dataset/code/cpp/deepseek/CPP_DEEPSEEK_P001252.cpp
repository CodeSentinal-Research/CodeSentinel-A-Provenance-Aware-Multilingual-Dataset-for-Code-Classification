#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    sort(pairs.begin(), pairs.end());

    int end = pairs[0].second;
    int maxLength = 1;

    for (int i = 1; i < n; i++) {
        if (pairs[i].first > end && pairs[i].second < end) {
            maxLength++;
            end = pairs[i].second;
        }
    }

    cout << maxLength;

    return 0;
}
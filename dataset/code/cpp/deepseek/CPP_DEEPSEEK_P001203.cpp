#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first && p1.second < p2.second;
}

int maxEnvelopes(vector<pair<int, int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(), compare);

    vector<int> dp(envelopes.size(), 1);
    int result = 0;

    for(int i = 1; i < envelopes.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> envelopes(n);

    for(int i = 0; i < n; i++) {
        cin >> envelopes[i].first >> envelopes[i].second;
    }

    cout << maxEnvelopes(envelopes) << "\n";

    return 0;
}
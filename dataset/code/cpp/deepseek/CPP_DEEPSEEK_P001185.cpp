#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solve(int n, vector<int> arr) {
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }

    vector<pair<int, int>> sortedNums;
    for (auto& kv : freq) {
        sortedNums.push_back({kv.first, kv.second});
    }
    sort(sortedNums.begin(), sortedNums.end());

    int maxPoints = 0;
    int curPoints = sortedNums[0].second;
    for (int i = 1; i < sortedNums.size(); ++i) {
        if (sortedNums[i].first - 1 != sortedNums[i - 1].first) {
            maxPoints += curPoints;
            curPoints = sortedNums[i].second;
        } else {
            curPoints = max(curPoints, sortedNums[i].second * 2);
        }
    }
    maxPoints += curPoints;

    return maxPoints;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(n, arr) << endl;
    return 0;
}
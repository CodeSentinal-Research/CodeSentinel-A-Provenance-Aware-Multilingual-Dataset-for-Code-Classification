#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> dp(n, 1);
    vector<int> parent(n, -1);
    int maxDivisibleSubsetSize = 0;
    int maxDivisibleSubsetEnd = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dp[i] > maxDivisibleSubsetSize) {
            maxDivisibleSubsetSize = dp[i];
            maxDivisibleSubsetEnd = i;
        }
    }

    cout << maxDivisibleSubsetSize << "\n";
    while (maxDivisibleSubsetEnd != -1) {
        cout << nums[maxDivisibleSubsetEnd] << " ";
        maxDivisibleSubsetEnd = parent[maxDivisibleSubsetEnd];
    }

    return 0;
}
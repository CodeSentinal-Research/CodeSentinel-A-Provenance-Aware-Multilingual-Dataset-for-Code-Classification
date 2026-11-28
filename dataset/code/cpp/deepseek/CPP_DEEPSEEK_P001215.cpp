#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeBoxes(vector<int>& boxes, int k) {
    int n = boxes.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (boxes[i] == boxes[j]) {
                dp[i][j] = dp[i + 1][j - 1] + (j - i) * (j - i) + 2 * dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> boxes(n);
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i];
    }
    cout << removeBoxes(boxes, 0) << endl;
    return 0;
}
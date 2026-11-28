#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];
    
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) dp[i][i] = nums[i];
    
    for (int len = 2; len <= N; ++len) {
        for (int i = 0; i <= N - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        }
    }
    
    cout << (dp[0][N-1] >= 0 ? "true" : "false") << endl;
    return 0;
}

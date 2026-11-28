#include <iostream>
#include <vector>
using namespace std;

int main() {
    int d, f, s;
    cin >> d >> f >> s;
    
    // dp[i][j] = number of ways to get sum j with i dice
    vector<vector<long long>> dp(d + 1, vector<long long>(s + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= d; ++i) {
        for (int j = 1; j <= s; ++j) {
            for (int k = 1; k <= f; ++k) {
                if (j - k >= 0) {
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }
    }
    
    cout << dp[d][s] << endl;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long dp[n + 1][2][2];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % 1000000007;
                if (j == 1) dp[i][j][1] = dp[i-1][j][0];
            }
        }
    }
    long long res = 0;
    for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
            res = (res + dp[n][j][k]) % 1000000007;
    cout << res << endl;
    return 0;
}

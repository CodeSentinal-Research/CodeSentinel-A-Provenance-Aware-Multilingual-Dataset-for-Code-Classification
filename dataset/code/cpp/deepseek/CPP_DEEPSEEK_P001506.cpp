#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S;
    string T;

    cin >> S;

    cin >> T;

    int S_len = S.length();
    int T_len = T.length();

    vector<vector<int>> dp(S_len + 1, vector<int>(T_len + 1, 0));

    for (int i = 1; i <= S_len; i++) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= T_len; j++) {
        for (int i = 1; i <= S_len; i++) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    int i = 0, j = 0;
    for (int x = 1; x <= S_len; x++) {
        if (dp[x][T_len] < dp[i][j]) {
            i = x;
        }
    }

    if (dp[S_len][T_len] < S_len) {
        cout << S.substr(i, T_len);
    } else {
        cout << "";
    }

    return 0;
}
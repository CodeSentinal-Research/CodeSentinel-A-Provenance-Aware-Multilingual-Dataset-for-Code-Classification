#include <iostream>
using namespace std;

int main() {
    int D, F, S;
    cin >> D >> F >> S;

    int dp[D+1][S+1];
    for(int i=0; i<=D; i++) {
        dp[i][0] = 1;
    }

    for(int i=1; i<=D; i++) {
        for(int j=1; j<=S; j++) {
            for(int k=1; k<=F; k++) {
                dp[i][j] += dp[i-1][j-k];
            }
        }
    }

    cout << dp[D][S];
    return 0;
}
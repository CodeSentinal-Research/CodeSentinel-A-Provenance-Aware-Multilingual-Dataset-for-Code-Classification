#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 0) { cout << 1 << endl; return 0; }
    
    vector<long long> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
        dp[i] = dp[i-1] * 10;
        if (i > 1) dp[i] -= dp[i-2] * (i - 1);
    }
    
    long long count = 0;
    for (int i = 0; i <= N; ++i) count += dp[i];
    
    cout << count << endl;
    return 0;
}

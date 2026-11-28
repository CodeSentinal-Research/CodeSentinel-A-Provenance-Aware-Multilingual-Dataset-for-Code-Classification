#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxStones(vector<int>& piles) {
    int N = piles.size();
    vector<int> dp(N + 1, 0);
    vector<int> sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        sum[i + 1] = sum[i] + piles[i];
    }
    for (int i = 0; i < N; ++i) {
        int x = 1;
        while (x <= 2 * (N - i)) {
            if (dp[i] < sum[N] - sum[i] + piles[i] - x) {
                dp[i + 1] = max(dp[i + 1], sum[N] - sum[i] + piles[i] - x);
            }
            x++;
        }
    }
    return dp[N];
}

int main() {
    int N;
    cin >> N;
    vector<int> piles(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> piles[i];
    }
    cout << getMaxStones(piles) << endl;
    return 0;
}
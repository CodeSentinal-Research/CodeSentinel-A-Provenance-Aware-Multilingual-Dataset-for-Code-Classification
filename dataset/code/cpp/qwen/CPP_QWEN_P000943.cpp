#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

vector<vector<int>> memo;
vector<int> prefix;

int solve(int i, int m, const vector<int>& piles) {
    int n = piles.size();
    if (i >= n) return 0;
    if (memo[i][m] != -1) return memo[i][m];
    
    int maxStones = 0;
    int totalTaken = 0;
    
    for (int x = 1; x <= 2 * m && i + x - 1 < n; ++x) {
        totalTaken += piles[i + x - 1];
        int remainingTotal = prefix[n] - prefix[i];
        int nextM = max(m, x);
        int opponentBest = solve(i + x, nextM, piles);
        int myStones = remainingTotal - opponentBest;
        maxStones = max(maxStones, myStones);
    }
    
    return memo[i][m] = maxStones;
}

int main() {
    int N;
    cin >> N;
    vector<int> piles(N);
    for (int i = 0; i < N; ++i) cin >> piles[i];
    
    prefix.resize(N + 1, 0);
    for (int i = 0; i < N; ++i) prefix[i+1] = prefix[i] + piles[i];
    
    memo.assign(N, vector<int>(N + 1, -1));
    
    cout << solve(0, 1, piles) << endl;
    return 0;
}

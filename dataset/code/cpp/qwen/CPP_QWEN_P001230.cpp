#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int r, c, k, sr, sc;
    cin >> r >> c >> k >> sr >> sc;
    sr--; sc--;
    
    // dp[step][i][j] = number of paths to (i, j) in step moves
    // We need paths that go OUT of bounds.
    // Total paths = 4^k. Paths staying in bounds = sum(dp[k][i][j]).
    // Answer = Total - InBounds.
    
    vector<vector<long long>> curr(r, vector<long long>(c, 0));
    curr[sr][sc] = 1;
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    for (int step = 0; step < k; ++step) {
        vector<vector<long long>> next(r, vector<long long>(c, 0));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (curr[i][j] > 0) {
                    for (int m = 0; m < 4; ++m) {
                        int ni = i + dr[m];
                        int nj = j + dc[m];
                        if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                            next[ni][nj] = (next[ni][nj] + curr[i][j]) % MOD;
                        }
                    }
                }
            }
        }
        curr = next;
    }
    
    long long inBounds = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            inBounds = (inBounds + curr[i][j]) % MOD;
        }
    }
    
    // Calculate 4^k mod MOD
    long long total = 1;
    long long base = 4;
    int exp = k;
    while (exp > 0) {
        if (exp % 2 == 1) total = (total * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    
    cout << (total - inBounds + MOD) % MOD << endl;
    return 0;
}

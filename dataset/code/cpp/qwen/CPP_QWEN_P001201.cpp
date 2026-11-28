#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];
            
    // dp[i][j] = min falling path sum ending at (i, j)
    // To optimize space, we can just keep previous row
    vector<int> prev = grid[0];
    
    for (int i = 1; i < n; ++i) {
        vector<int> curr(n, INT_MAX);
        // Precompute min1 and min2 of prev row to avoid O(N^2) inner loop if needed, 
        // but standard DP is O(N^2) which is fine for N=500.
        // Actually, constraint says N<=500, so O(N^2) is 250k ops, very fast.
        // But problem says "No two consecutive chosen elements are from same column".
        // This implies we pick one element from each row.
        
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (k != j) {
                    curr[j] = min(curr[j], prev[k] + grid[i][j]);
                }
            }
        }
        prev = curr;
    }
    
    cout << *min_element(prev.begin(), prev.end()) << endl;
    return 0;
}

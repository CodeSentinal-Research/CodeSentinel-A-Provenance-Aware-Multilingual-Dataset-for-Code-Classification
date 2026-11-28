#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // Compute 2D Prefix Sum for 1s
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    auto getCountOnes = [&](int r1, int c1, int r2, int c2) -> int {
        return prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
    };
    
    long long count = 0;
    int totalCells = n * m;
    
    for (int r1 = 0; r1 < n; ++r1) {
        for (int c1 = 0; c1 < m; ++c1) {
            for (int r2 = r1; r2 < n; ++r2) {
                for (int c2 = c1; c2 < m; ++c2) {
                    int ones = getCountOnes(r1, c1, r2, c2);
                    int area = (r2 - r1 + 1) * (c2 - c1 + 1);
                    if (ones == area / 2 && area % 2 == 0) {
                         // Equal 0s and 1s means ones = zeros = area/2
                         count++;
                    } else if (ones == (area + 1) / 2 && area % 2 != 0) {
                         // Cannot have equal 0s and 1s if area is odd
                    }
                    
                    // Correct condition: ones == zeros => ones == area - ones => 2*ones == area
                    if (2 * ones == area) {
                        count++;
                    }
                }
            }
        }
    }
    
    cout << count << endl;
    return 0;
}

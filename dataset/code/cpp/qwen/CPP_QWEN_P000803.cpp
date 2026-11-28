#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N, M, target;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
    cin >> target;

    // Prefix sum for rows
    vector<vector<int>> rowPrefix(N, vector<int>(M + 1, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            rowPrefix[i][j+1] = rowPrefix[i][j] + grid[i][j];
        }
    }

    long long count = 0;
    // Fix top and bottom rows
    for (int top = 0; top < N; ++top) {
        vector<int> colSum(M, 0);
        for (int bottom = top; bottom < N; ++bottom) {
            for (int c = 0; c < M; ++c) {
                colSum[c] += grid[bottom][c];
            }
            
            // Now find subarrays in colSum with sum == target
            unordered_map<int, int> prefixCount;
            prefixCount[0] = 1;
            int currentSum = 0;
            for (int c = 0; c < M; ++c) {
                currentSum += colSum[c];
                if (prefixCount.find(currentSum - target) != prefixCount.end()) {
                    count += prefixCount[currentSum - target];
                }
                prefixCount[currentSum]++;
            }
        }
    }

    cout << count << endl;
    return 0;
}

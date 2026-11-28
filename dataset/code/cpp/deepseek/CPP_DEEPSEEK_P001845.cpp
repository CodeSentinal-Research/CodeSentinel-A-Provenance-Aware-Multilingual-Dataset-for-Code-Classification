Here is the complete C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countTrees(vector<int>& arr, int n, vector<int>& tree, int m, vector<int>& dp) {
    if (n == 0) return 1;

    long long res = 0;

    if (dp[n] != -1) return dp[n];

    for (int i = 0; i < m; i++) {
        if (n == 0 || arr[n - 1] < tree[i]) {
            res += countTrees(arr, n - 1, tree, m, dp);
        }
    }

    return dp[n] = res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> m;

        vector<vector<int>> sequences(m);
        for (int i = 0; i < m; i++) {
            int n;
            cin >> n;
            sequences[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> sequences[i][j];
            }
        }

        long long result = 0;
        for (int i = 0; i < m; i++) {
            vector<int> tree(sequences[i]);
            sort(tree.begin(), tree.end());

            vector<int> dp(sequences[i].size() + 1, -1);
            result += countTrees(sequences[i], sequences[i].size(), tree, m, dp);
        }

        cout << result << "\n";
    }

    return 0;
}

This program reads the number of sequences and then for each sequence, it reads the length and insertion sequence. Then it finds the distinct binary search trees for each sequence and sums them up. The result is then printed out.
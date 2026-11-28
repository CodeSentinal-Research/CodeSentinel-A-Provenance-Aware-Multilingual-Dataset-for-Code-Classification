#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    const int MOD = 1e9 + 7;
    std::vector<std::vector<long long>> comb;

    void precompute() {
        comb.assign(1005, std::vector<long long>(1005, 0));
        for (int i = 0; i <= 1000; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
    }

    std::pair<long long, int> dfs(TreeNode* node) {
        if (!node) return {1, 0};
        auto [lWays, lSize] = dfs(node->left);
        auto [rWays, rSize] = dfs(node->right);

        int total = lSize + rSize;
        long long c = comb[total][lSize];
        long long ways = (((lWays * rWays) % MOD) * c) % MOD;
        return {ways, total + 1};
    }
public:
    int countValidInsertionSeqs(TreeNode* root) {
        precompute();
        return dfs(root).first;
    }
};
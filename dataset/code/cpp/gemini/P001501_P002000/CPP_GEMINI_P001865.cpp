#include <vector>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* build(std::vector<int>& keys, std::vector<std::vector<int>>& rootIdx, int i, int j) {
        if (i > j) return nullptr;
        int r = rootIdx[i][j];
        TreeNode* node = new TreeNode(keys[r]);
        node->left = build(keys, rootIdx, i, r - 1);
        node->right = build(keys, rootIdx, r + 1, j);
        return node;
    }
public:
    TreeNode* constructOBST(std::vector<int>& keys, std::vector<int>& freq) {
        int n = keys.size();
        std::vector<std::vector<int>> cost(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> rootIdx(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> w(n, std::vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            w[i][i] = freq[i];
            cost[i][i] = freq[i];
            rootIdx[i][i] = i;
            for (int j = i + 1; j < n; j++) {
                w[i][j] = w[i][j - 1] + freq[j];
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                cost[i][j] = INT_MAX;
                for (int r = i; r <= j; r++) {
                    int c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0) + w[i][j];
                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                        rootIdx[i][j] = r;
                    }
                }
            }
        }

        return build(keys, rootIdx, 0, n - 1);
    }
};
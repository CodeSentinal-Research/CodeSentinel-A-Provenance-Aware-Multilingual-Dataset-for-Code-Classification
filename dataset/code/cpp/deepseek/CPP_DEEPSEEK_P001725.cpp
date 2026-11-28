#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countPaths(TreeNode* root, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        dfs(root, k, 0, count);
        return count[k];
    }

private:
    void dfs(TreeNode* node, int k, int sum, unordered_map<int, int>& count) {
        if (!node) {
            return;
        }
        sum += node->val;
        if (count.find(sum - k) != count.end()) {
            count[sum] += count[sum - k];
        }
        ++count[sum];
        dfs(node->left, k, sum, count);
        dfs(node->right, k, sum, count);
        --count[sum];
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }
    TreeNode* root = new TreeNode(nodes[0]);
    for (int i = 1; i < n; ++i) {
        TreeNode* parent = nullptr;
        if (nodes[i] / 2 < n) {
            parent = new TreeNode(nodes[i / 2]);
            if (i % 2 == 0) {
                parent->left = new TreeNode(nodes[i]);
            } else {
                parent->right = new TreeNode(nodes[i]);
            }
        } else {
            parent = new TreeNode(nodes[i / 2]);
            parent->left = new TreeNode(nodes[i]);
        }
        if (i == 1) {
            root = parent;
        } else {
            if (nodes[i] / 2 < n) {
                if (nodes[i] % 2 == 0) {
                    parent->left->parent = parent;
                } else {
                    parent->right->parent = parent;
                }
            } else {
                parent->left->parent = parent;
            }
        }
    }
    cin >> k;
    Solution solution;
    cout << solution.countPaths(root, k) << "\n";
    return 0;
}
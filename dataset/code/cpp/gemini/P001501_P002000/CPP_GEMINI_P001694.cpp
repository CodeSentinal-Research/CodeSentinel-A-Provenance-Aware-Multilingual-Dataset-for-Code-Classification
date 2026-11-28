#include <unordered_map>
#include <unordered_set>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* targetNode = nullptr;
    std::unordered_map<TreeNode*, TreeNode*> parentMap;

    void dfs(TreeNode* node, TreeNode* parent, int k) {
        if (!node) return;
        if (node->val == k) targetNode = node;
        parentMap[node] = parent;
        dfs(node->left, node, k);
        dfs(node->right, node, k);
    }
public:
    int findClosestLeaf(TreeNode* root, int k) {
        parentMap.clear();
        targetNode = nullptr;
        dfs(root, nullptr, k);

        std::unordered_set<TreeNode*> visited{targetNode};
        std::queue<TreeNode*> q;
        q.push(targetNode);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!curr->left && !curr->right) return curr->val;

            std::vector<TreeNode*> neighbors{curr->left, curr->right, parentMap[curr]};
            for (TreeNode* next : neighbors) {
                if (next && !visited.count(next)) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        return -1;
    }
};
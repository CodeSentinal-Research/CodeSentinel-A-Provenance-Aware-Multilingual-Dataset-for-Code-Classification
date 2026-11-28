#include <vector>
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
    std::unordered_map<TreeNode*, TreeNode*> parentMap;

    void mapParents(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        parentMap[node] = parent;
        mapParents(node->left, node);
        mapParents(node->right, node);
    }
public:
    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parentMap.clear();
        mapParents(root, nullptr);

        std::unordered_set<TreeNode*> visited{target};
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({target, 0});
        std::vector<int> res;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (dist == k) {
                res.push_back(node->val);
            } else if (dist < k) {
                std::vector<TreeNode*> neighbors{node->left, node->right, parentMap[node]};
                for (TreeNode* next : neighbors) {
                    if (next && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, dist + 1});
                    }
                }
            }
        }
        return res;
    }
};
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

    void mapParents(TreeNode* node, TreeNode* parent, int start) {
        if (!node) return;
        if (node->val == start) targetNode = node;
        parentMap[node] = parent;
        mapParents(node->left, node, start);
        mapParents(node->right, node, start);
    }
public:
    int minTimeToBurn(TreeNode* root, int start) {
        parentMap.clear();
        targetNode = nullptr;
        mapParents(root, nullptr, start);

        std::unordered_set<TreeNode*> visited{targetNode};
        std::queue<TreeNode*> q;
        q.push(targetNode);
        int time = 0;

        while (!q.empty()) {
            size_t size = q.size();
            bool burned = false;
            for (size_t i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();

                std::vector<TreeNode*> neighbors{cur->left, cur->right, parentMap[cur]};
                for (TreeNode* next : neighbors) {
                    if (next && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                        burned = true;
                    }
                }
            }
            if (burned) time++;
        }
        return time;
    }
};
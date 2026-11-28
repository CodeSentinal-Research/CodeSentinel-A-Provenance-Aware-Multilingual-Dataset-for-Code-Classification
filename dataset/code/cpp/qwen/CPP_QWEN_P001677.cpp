#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> cousins(TreeNode* root, int target) {
    if (!root) return {};
    queue<pair<TreeNode*, TreeNode*>> q; // node, parent
    q.push({root, NULL});
    vector<int> result;
    bool foundTargetLevel = false;
    
    while (!q.empty() && !foundTargetLevel) {
        int size = q.size();
        unordered_map<TreeNode*, vector<int>> parentChildren;
        bool foundTarget = false;
        
        for (int i = 0; i < size; ++i) {
            auto [node, parent] = q.front(); q.pop();
            if (node->val == target) foundTarget = true;
            if (parent) parentChildren[parent].push_back(node->val);
            if (node->left) q.push({node->left, node});
            if (node->right) q.push({node->right, node});
        }
        
        if (foundTarget) {
            for (auto& p : parentChildren) {
                bool isSibling = false;
                for (int val : p.second) {
                    if (val == target) isSibling = true;
                }
                if (!isSibling) {
                    for (int val : p.second) result.push_back(val);
                }
            }
            foundTargetLevel = true;
        }
    }
    return result;
}

int main() {
    int n, target;
    cin >> n >> target;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}

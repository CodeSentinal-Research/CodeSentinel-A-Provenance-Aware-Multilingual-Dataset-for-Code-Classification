#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return NULL;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < vals.size() && vals[i] != -1) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != -1) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

vector<vector<int>> removeLeavesIterative(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    while (root) {
        vector<int> leaves;
        queue<pair<TreeNode*, TreeNode*>> q; // node, parent
        q.push({root, NULL});
        
        TreeNode* newRoot = NULL;
        while (!q.empty()) {
            auto [node, parent] = q.front(); q.pop();
            
            if (!node->left && !node->right) {
                leaves.push_back(node->val);
                if (parent) {
                    if (parent->left == node) parent->left = NULL;
                    else parent->right = NULL;
                } else {
                    newRoot = NULL; // Root was a leaf
                }
            } else {
                if (!newRoot) newRoot = node;
                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }
        }
        
        if (!leaves.empty()) {
            result.push_back(leaves);
        }
        root = newRoot;
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    vector<vector<int>> rounds = removeLeavesIterative(root);
    
    for (auto& round : rounds) {
        for (int val : round) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

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

TreeNode* findKthAncestor(TreeNode* root, int target, int k, vector<int>& path) {
    if (!root) return NULL;
    
    path.push_back(root->val);
    
    if (root->val == target) {
        if (path.size() > k) {
            return new TreeNode(path[path.size() - k - 1]);
        }
        return NULL;
    }
    
    TreeNode* left = findKthAncestor(root->left, target, k, path);
    if (left) return left;
    
    TreeNode* right = findKthAncestor(root->right, target, k, path);
    if (right) return right;
    
    path.pop_back();
    return NULL;
}

int main() {
    int n, target, k;
    cin >> n >> target >> k;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    vector<int> path;
    TreeNode* ancestor = findKthAncestor(root, target, k, path);
    
    if (ancestor) {
        cout << ancestor->val << endl;
    } else {
        cout << "NONE" << endl;
    }
    
    return 0;
}

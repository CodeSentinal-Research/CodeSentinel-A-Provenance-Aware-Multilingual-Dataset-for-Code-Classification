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

TreeNode* findLCA_BST(TreeNode* root, int p, int q) {
    if (!root) return NULL;
    if (p < root->val && q < root->val) return findLCA_BST(root->left, p, q);
    if (p > root->val && q > root->val) return findLCA_BST(root->right, p, q);
    return root;
}

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    TreeNode* lca = findLCA_BST(root, p, q);
    
    if (lca) cout << lca->val << endl;
    
    return 0;
}

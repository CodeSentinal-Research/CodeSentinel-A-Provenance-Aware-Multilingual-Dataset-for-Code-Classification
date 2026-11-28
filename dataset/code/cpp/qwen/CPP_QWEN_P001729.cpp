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

TreeNode* findLCA(TreeNode* root, int p, int q) {
    if (!root || root->val == p || root->val == q) return root;
    
    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);
    
    if (left && right) return root;
    return left ? left : right;
}

int findDistance(TreeNode* root, int target, int dist) {
    if (!root) return -1;
    if (root->val == target) return dist;
    
    int left = findDistance(root->left, target, dist + 1);
    if (left != -1) return left;
    
    return findDistance(root->right, target, dist + 1);
}

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    TreeNode* lca = findLCA(root, p, q);
    
    int distP = findDistance(lca, p, 0);
    int distQ = findDistance(lca, q, 0);
    
    cout << distP + distQ << endl;
    
    return 0;
}

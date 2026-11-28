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

int getSize(TreeNode* root) {
    if (!root) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

TreeNode* findCentroid(TreeNode* root, int totalSize) {
    if (!root) return NULL;
    
    // Check if root is centroid
    bool isCentroid = true;
    int leftSize = getSize(root->left);
    int rightSize = getSize(root->right);
    
    if (leftSize > totalSize / 2 || rightSize > totalSize / 2) {
        isCentroid = false;
    }
    
    if (isCentroid) return root;
    
    if (leftSize > rightSize) {
        return findCentroid(root->left, totalSize);
    } else {
        return findCentroid(root->right, totalSize);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    TreeNode* centroid = findCentroid(root, getSize(root));
    
    if (centroid) cout << centroid->val << endl;
    
    return 0;
}

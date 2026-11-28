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

bool isSymmetric(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) && isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
}

int findLargestSymmetricSubtree(TreeNode* root) {
    if (!root) return 0;
    int size = isSymmetric(root->left, root->right) ? getSize(root) : 0;
    return max(size, max(findLargestSymmetricSubtree(root->left), findLargestSymmetricSubtree(root->right)));
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    cout << findLargestSymmetricSubtree(root) << endl;
    
    return 0;
}

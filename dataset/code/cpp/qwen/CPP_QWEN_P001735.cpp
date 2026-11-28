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

TreeNode* mirrorTree(TreeNode* root) {
    if (!root) return NULL;
    TreeNode* mirrored = new TreeNode(root->val);
    mirrored->left = mirrorTree(root->right);
    mirrored->right = mirrorTree(root->left);
    return mirrored;
}

bool isSubtree(TreeNode* t1, TreeNode* t2) {
    if (!t2) return true;
    if (!t1) return false;
    
    if (t1->val == t2->val) {
        if (isIdentical(t1->left, t2->left) && isIdentical(t1->right, t2->right)) {
            return true;
        }
    }
    
    return isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
}

bool isIdentical(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) && isIdentical(t1->left, t2->left) && isIdentical(t1->right, t2->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    TreeNode* mirrored = mirrorTree(root);
    
    cout << (isSubtree(root, mirrored) ? "YES" : "NO") << endl;
    
    return 0;
}

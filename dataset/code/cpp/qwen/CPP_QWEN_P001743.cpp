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

int findFirstNonFullNode(TreeNode* root) {
    if (!root) return -1;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (!(node->left && node->right)) {
            return node->val;
        }
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    int result = findFirstNonFullNode(root);
    
    if (result != -1) cout << result << endl;
    else cout << "NONE" << endl;
    
    return 0;
}

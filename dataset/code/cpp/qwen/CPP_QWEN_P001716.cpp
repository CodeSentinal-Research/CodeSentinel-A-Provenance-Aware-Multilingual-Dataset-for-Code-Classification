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

void findDeepestLeftLeaf(TreeNode* root, int& maxDepth, int& result, int depth, bool isLeft) {
    if (!root) return;
    
    if (!root->left && !root->right && isLeft) {
        if (depth > maxDepth) {
            maxDepth = depth;
            result = root->val;
        }
    }
    
    findDeepestLeftLeaf(root->left, maxDepth, result, depth + 1, true);
    findDeepestLeftLeaf(root->right, maxDepth, result, depth + 1, false);
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    int maxDepth = -1;
    int result = -1;
    findDeepestLeftLeaf(root, maxDepth, result, 0, false);
    
    if (result != -1) cout << result << endl;
    else cout << "NONE" << endl;
    
    return 0;
}

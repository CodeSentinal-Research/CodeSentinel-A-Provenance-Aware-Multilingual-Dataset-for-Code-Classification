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

void printBoundary(TreeNode* root) {
    if (!root) return;
    
    cout << root->val << " ";
    
    // Left boundary
    TreeNode* curr = root->left;
    vector<int> leftNodes;
    while (curr) {
        if (curr->left || curr->right) {
            leftNodes.push_back(curr->val);
        }
        curr = curr->left ? curr->left : curr->right;
    }
    for (int val : leftNodes) cout << val << " ";
    
    // Leaves
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (!node->left && !node->right && node != root) {
            cout << node->val << " ";
        }
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    
    // Right boundary
    curr = root->right;
    vector<int> rightNodes;
    while (curr) {
        if (curr->left || curr->right) {
            rightNodes.push_back(curr->val);
        }
        curr = curr->right ? curr->right : curr->left;
    }
    for (int i = rightNodes.size() - 1; i >= 0; --i) {
        cout << rightNodes[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    printBoundary(root);
    
    return 0;
}

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

int getHeight(TreeNode* root) {
    if (!root) return -1;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool checkEqualPathLengths(TreeNode* root, int& expectedHeight) {
    if (!root) return true;
    if (!root->left && !root->right) {
        if (expectedHeight == -1) {
            expectedHeight = 0;
            return true;
        }
        return expectedHeight == 0;
    }
    
    int h = -1;
    bool valid = true;
    if (root->left) {
        if (!checkEqualPathLengths(root->left, h)) return false;
        if (expectedHeight == -1) expectedHeight = h + 1;
        else if (expectedHeight != h + 1) return false;
    }
    if (root->right) {
        if (!checkEqualPathLengths(root->right, h)) return false;
        if (expectedHeight == -1) expectedHeight = h + 1;
        else if (expectedHeight != h + 1) return false;
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    int expectedHeight = -1;
    cout << (checkEqualPathLengths(root, expectedHeight) ? "YES" : "NO") << endl;
    
    return 0;
}

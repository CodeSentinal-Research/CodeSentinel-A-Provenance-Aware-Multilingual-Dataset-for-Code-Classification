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

TreeNode* buildTreeFromLevelAndInorder(vector<int>& level, vector<int>& inorder) {
    if (level.empty()) return NULL;
    
    TreeNode* root = new TreeNode(level[0]);
    
    int idx = -1;
    for (int i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == level[0]) {
            idx = i;
            break;
        }
    }
    
    vector<int> leftIn(inorder.begin(), inorder.begin() + idx);
    vector<int> rightIn(inorder.begin() + idx + 1, inorder.end());
    
    vector<int> leftLevel, rightLevel;
    for (int i = 1; i < level.size(); ++i) {
        if (find(leftIn.begin(), leftIn.end(), level[i]) != leftIn.end()) {
            leftLevel.push_back(level[i]);
        } else if (find(rightIn.begin(), rightIn.end(), level[i]) != rightIn.end()) {
            rightLevel.push_back(level[i]);
        }
    }
    
    root->left = buildTreeFromLevelAndInorder(leftLevel, leftIn);
    root->right = buildTreeFromLevelAndInorder(rightLevel, rightIn);
    
    return root;
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> level(n), inorder(n);
    for (int i = 0; i < n; ++i) cin >> level[i];
    for (int i = 0; i < n; ++i) cin >> inorder[i];
    
    TreeNode* root = buildTreeFromLevelAndInorder(level, inorder);
    printLevelOrder(root);
    
    return 0;
}

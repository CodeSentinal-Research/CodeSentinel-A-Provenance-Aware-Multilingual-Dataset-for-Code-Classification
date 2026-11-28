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

void countAncestors(TreeNode* root, vector<int>& ancestors, vector<int>& result) {
    if (!root) return;
    
    result.push_back(ancestors.size());
    ancestors.push_back(root->val);
    
    countAncestors(root->left, ancestors, result);
    countAncestors(root->right, ancestors, result);
    
    ancestors.pop_back();
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    vector<int> ancestors, result;
    countAncestors(root, ancestors, result);
    
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;
    
    return 0;
}

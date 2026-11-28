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

pair<int, int> findMaxIndependentSet(TreeNode* root) {
    if (!root) return {0, 0};
    
    auto left = findMaxIndependentSet(root->left);
    auto right = findMaxIndependentSet(root->right);
    
    int include = 1 + left.second + right.second;
    int exclude = max(left.first, left.second) + max(right.first, right.second);
    
    return {include, exclude};
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    auto result = findMaxIndependentSet(root);
    cout << max(result.first, result.second) << endl;
    
    return 0;
}

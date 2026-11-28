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

void findLongestDecreasingPath(TreeNode* root, vector<int>& path, vector<int>& longest) {
    if (!root) return;
    
    path.push_back(root->val);
    
    if (!root->left && !root->right) {
        if (path.size() > longest.size()) {
            bool dec = true;
            for (int i = 1; i < path.size(); ++i) {
                if (path[i] >= path[i-1]) {
                    dec = false;
                    break;
                }
            }
            if (dec) longest = path;
        }
    }
    
    findLongestDecreasingPath(root->left, path, longest);
    findLongestDecreasingPath(root->right, path, longest);
    
    path.pop_back();
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    vector<int> path, longest;
    findLongestDecreasingPath(root, path, longest);
    
    for (int val : longest) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

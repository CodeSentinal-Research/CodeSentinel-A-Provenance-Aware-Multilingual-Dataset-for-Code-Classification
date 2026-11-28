#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

int maxWidth(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    int maxW = 0;
    
    while (!q.empty()) {
        int size = q.size();
        long long minIdx = q.front().second;
        long long first, last;
        
        for (int i = 0; i < size; ++i) {
            auto [node, idx] = q.front(); q.pop();
            idx -= minIdx;
            if (i == 0) first = idx;
            if (i == size - 1) last = idx;
            
            if (node->left) q.push({node->left, 2 * idx + 1});
            if (node->right) q.push({node->right, 2 * idx + 2});
        }
        maxW = max(maxW, (int)(last - first + 1));
    }
    return maxW;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    cout << maxWidth(root) << endl;
    
    return 0;
}

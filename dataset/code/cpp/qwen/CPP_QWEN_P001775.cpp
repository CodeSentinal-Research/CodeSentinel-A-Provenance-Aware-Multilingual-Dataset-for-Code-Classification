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

int findMaxLevelDiff(TreeNode* root) {
    if (!root) return 0;
    
    queue<TreeNode*> q;
    q.push(root);
    long long prevSum = 0;
    int maxDiff = 0;
    bool first = true;
    
    while (!q.empty()) {
        int size = q.size();
        long long currSum = 0;
        
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            currSum += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        if (!first) {
            maxDiff = max(maxDiff, (int)abs(currSum - prevSum));
        }
        prevSum = currSum;
        first = false;
    }
    return maxDiff;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    cout << findMaxLevelDiff(root) << endl;
    
    return 0;
}

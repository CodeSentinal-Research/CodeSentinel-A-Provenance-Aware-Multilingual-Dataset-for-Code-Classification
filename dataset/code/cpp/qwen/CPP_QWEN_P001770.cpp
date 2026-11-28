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

void replaceWithLevelSum(TreeNode* root) {
    if (!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    vector<long long> levelSums;
    
    // First pass: calculate level sums
    while (!q.empty()) {
        int size = q.size();
        long long sum = 0;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            sum += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        levelSums.push_back(sum);
    }
    
    // Second pass: replace values
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            node->val = levelSums[level] - node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        level++;
    }
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
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    replaceWithLevelSum(root);
    printLevelOrder(root);
    
    return 0;
}

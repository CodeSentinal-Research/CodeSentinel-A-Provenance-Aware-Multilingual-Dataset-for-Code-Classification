#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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

int countPathsWithSumK(TreeNode* root, long long k, unordered_map<long long, int>& prefixSum, long long currSum) {
    if (!root) return 0;
    
    currSum += root->val;
    int count = prefixSum.count(currSum - k) ? prefixSum[currSum - k] : 0;
    
    prefixSum[currSum]++;
    
    count += countPathsWithSumK(root->left, k, prefixSum, currSum);
    count += countPathsWithSumK(root->right, k, prefixSum, currSum);
    
    prefixSum[currSum]--;
    
    return count;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    unordered_map<long long, int> prefixSum;
    prefixSum[0] = 1;
    
    cout << countPathsWithSumK(root, k, prefixSum, 0) << endl;
    
    return 0;
}

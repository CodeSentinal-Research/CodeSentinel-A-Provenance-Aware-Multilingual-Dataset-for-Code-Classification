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

int maxSumLevel(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int maxSum = INT_MIN;
    int level = 0;
    int resultLevel = 0;
    
    while (!q.empty()) {
        int size = q.size();
        long long currentSum = 0;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            currentSum += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        level++;
        if (currentSum > maxSum) {
            maxSum = currentSum;
            resultLevel = level;
        }
    }
    return resultLevel;
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL) return 0;
        int minVal = root->val, maxVal = root->val, maxDiff = INT_MIN;
        helper(root, minVal, maxVal, maxDiff);
        return maxDiff;
    }

private:
    void helper(TreeNode* node, int& minVal, int& maxVal, int& maxDiff) {
        if (node == NULL) return;
        maxDiff = max(maxDiff, max(abs(node->val - minVal), abs(node->val - maxVal)));
        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);
        helper(node->left, minVal, maxVal, maxDiff);
        helper(node->right, minVal, maxVal, maxDiff);
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> nodes(N);
    for (int i = 0; i < N; ++i) {
        cin >> nodes[i];
    }
    TreeNode* root = new TreeNode(nodes[0]);
    TreeNode* prev = root;
    for (int i = 1; i < N; ++i) {
        TreeNode* node = new TreeNode(nodes[i]);
        if (i % 2 == 1) {
            prev->left = node;
        } else {
            prev->right = node;
        }
        prev = node;
    }
    Solution solution;
    cout << solution.maxAncestorDiff(root) << endl;
    return 0;
}
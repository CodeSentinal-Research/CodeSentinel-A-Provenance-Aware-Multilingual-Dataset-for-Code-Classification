Here is the code snippet:

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int> &data, int index) {
    if (index >= data.size() || data[index] == -1) {
        return NULL;
    }
    TreeNode* node = new TreeNode(data[index]);
    node->left = buildTree(data, 2 * index + 1);
    node->right = buildTree(data, 2 * index + 2);
    return node;
}

void averageOfLevels(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        double sum = 0;
        int count = 0;
        queue<TreeNode*> next_level;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;
            count++;
            if (node->left != NULL) {
                next_level.push(node->left);
            }
            if (node->right != NULL) {
                next_level.push(node->right);
            }
        }
        cout << sum / count << endl;
        q = next_level;
    }
}

int main() {
    vector<int> data = {1, 2, 3, -1, -1, 4, -1, -1};
    TreeNode* root = buildTree(data, 0);
    averageOfLevels(root);
    return 0;
}

This code first builds a binary tree from the provided data. Then, it calculates the average of the node values at every level and prints the result.
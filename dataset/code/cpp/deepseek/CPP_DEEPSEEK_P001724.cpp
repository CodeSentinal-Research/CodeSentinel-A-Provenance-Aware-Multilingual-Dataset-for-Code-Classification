Here is a simple C++ solution for the problem:

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int MinimumRootToLeafSum(std::vector<TreeNode*> nodes, int start) {
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({nodes[start], 0});
    int minSum = INT_MAX;
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int pathSum = q.front().second;
        q.pop();
        if (node->left == NULL && node->right == NULL) {
            minSum = std::min(minSum, pathSum + node->val);
        }
        if (node->left != NULL) {
            q.push({node->left, pathSum + node->val});
        }
        if (node->right != NULL) {
            q.push({node->right, pathSum + node->val});
        }
    }
    return minSum;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<TreeNode*> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = new TreeNode(std::cin.get());
        if (i > 0) {
            nodes[i-1]->left = nodes[i];
            nodes[i-1]->right = nodes[i];
        }
    }
    std::cout << MinimumRootToLeafSum(nodes, 0);
    return 0;
}

This code first reads the number of nodes in the tree, then it reads each node's value and creates a binary tree from the input. It then calculates the minimum root-to-leaf sum by using a breadth-first search.
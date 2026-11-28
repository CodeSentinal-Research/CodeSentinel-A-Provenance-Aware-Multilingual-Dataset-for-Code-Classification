Here is the C++ code for the problem.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;

    queue<TreeNode*> q;
    q.push(root);
    bool flag = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> vec(size);

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            int index = flag ? i : size - 1 - i;
            vec[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        flag = !flag;
        res.push_back(vec);
    }

    return res;
}

int main() {
    return 0;
}

This program works by using a breadth-first search (BFS) strategy with a queue. For each level, it processes the nodes one by one from left to right for the first level and right to left for the second level. This alternation is represented by the flag variable.
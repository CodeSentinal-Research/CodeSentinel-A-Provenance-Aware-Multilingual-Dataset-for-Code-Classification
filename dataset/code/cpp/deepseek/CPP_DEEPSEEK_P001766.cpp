Here is a simple C++ solution for the problem. The code uses level order traversal to find the median of each level.

#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> medianOfEachLevel(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<double> res;
        while (!q.empty()) {
            int size = q.size();
            double median = 0;
            int count = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                median += node->val;
                count++;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            median /= count;
            res.push_back(median);
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;
    TreeNode* root = new TreeNode(cin.get());

    for (int i = 0; i < n - 1; ++i) {
        int parent, left, right;
        cin >> parent >> left >> right;

        TreeNode* node = new TreeNode(parent);
        if (left != -1) {
            node->left = new TreeNode(left);
        }
        if (right != -1) {
            node->right = new TreeNode(right);
        }

        if (i == 0) root = node;
    }

    Solution s;
    vector<double> res = s.medianOfEachLevel(root);
    for (double d : res) {
        cout << setprecision(1) << fixed << d << " ";
    }

    return 0;
}
This code reads the tree from standard input, builds the tree, and then finds the median of the node values at every level. The tree is represented as a binary tree, and each node is represented by a line containing the node's value and the indices of its children (-1 if the child does not exist).

The code uses a queue to perform level order traversal. At each level, it calculates the median of the node values and adds it to the result vector.

The main function reads the number of nodes, and then the root of the tree. It then constructs the tree and calls the function to find the median of the node values at every level.

Please note that the input for the tree is given in the format described above. The code also assumes that the input is valid, i.e., the tree is correctly formed and all the children indices are valid.
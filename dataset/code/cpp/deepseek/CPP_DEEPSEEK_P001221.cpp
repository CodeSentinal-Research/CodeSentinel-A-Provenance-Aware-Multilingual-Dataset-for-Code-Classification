Here is the C++ code for generating all unique Binary Search Trees for a given integer N:

#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees(int start, int end) {
    vector<TreeNode*> trees;
    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++) {
        for (TreeNode* left : generateTrees(start, i - 1)) {
            for (TreeNode* right : generateTrees(i + 1, end)) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        }
    }

    return trees;
}

int countTrees(int n) {
    vector<TreeNode*> trees = generateTrees(1, n);
    return trees.size();
}

int main() {
    int n;
    cin >> n;
    cout << countTrees(n) << endl;
    return 0;
}

This code first defines a TreeNode class and the generateTrees function, which generates all unique BSTs for a given range. The generateTrees function works by generating all possible binary trees for the given range and returning them as a vector.

The countTrees function calls generateTrees to generate all unique BSTs for the given range and then returns the size of the returned vector, which represents the count of unique BSTs.

In the main function, the code reads an integer n from the standard input and prints the count of unique BSTs for the given range 1 to n.
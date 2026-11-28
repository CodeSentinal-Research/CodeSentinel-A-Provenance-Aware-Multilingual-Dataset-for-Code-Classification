Here is the code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return vector<TreeNode*>(1, NULL);

    vector<int> keys(n);
    for (int i = 0; i < n; i++) keys[i] = i + 1; 

    return generateAll(keys, 0, n - 1);
}

vector<TreeNode*> generateAll(vector<int>& nums, int start, int end) {
    vector<TreeNode*> trees;
    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++) {
        vector<TreeNode*> leftTrees = generateAll(nums, start, i - 1);
        vector<TreeNode*> rightTrees = generateAll(nums, i + 1, end);

        for (int j = 0; j < leftTrees.size(); j++) {
            for (int k = 0; k < rightTrees.size(); k++) {
                TreeNode* root = new TreeNode(nums[i]);
                root->left = leftTrees[j];
                root->right = rightTrees[k];
                trees.push_back(root);
            }
        }
    }

    return trees;
}

int main() {
    int n;
    cin >> n;

    vector<TreeNode*> trees = generateTrees(n);
    for (int i = 0; i < trees.size(); i++) {
    }

    return 0;
}
This code first constructs a vector of keys from 1 to n. Then it calls the `generateAll` function to generate all unique Binary Search Trees with these keys. The `generateAll` function takes a vector of keys, two indices representing the range of keys to consider (inclusive), and returns a vector of pointers to the root of all unique BSTs that can be constructed with the given keys.
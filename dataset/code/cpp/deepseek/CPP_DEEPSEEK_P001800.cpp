Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int maxIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }
    TreeNode* root = new TreeNode(nums[maxIndex]);
    root->left = constructMaximumBinaryTree(nums, start, maxIndex - 1);
    root->right = constructMaximumBinaryTree(nums, maxIndex + 1, end);
    return root;
}

TreeNode* recoverFromPreorder(string S) {
    int i = 0, val = 0, depth = 0;
    vector<int> nums;
    while (i < S.size()) {
        if (S[i] == '-') {
            i++;
            while (i < S.size() && S[i] != '-') {
                i++;
            }
            depth++;
        } else {
            while (i < S.size() && S[i] != '-') {
                i++;
            }
            nums.push_back(stoi(S.substr(i - depth, depth)));
        }
    }
    return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
}

int main() {
    string S;
    cin >> S;
    TreeNode* root = recoverFromPreorder(S);
    return 0;
}

In this code, we use a postorder traversal approach to construct the binary search tree. We first parse the input string to get the node values and depths. Then we use these values to construct the binary search tree.

Please note that this code will not work if the input string S is not a valid representation of a binary search tree. Also, this code assumes that the input string S is a correct representation of a binary search tree, i.e., each node's value is either a positive integer or a negative integer, and all left child nodes of a node come before its right child nodes.
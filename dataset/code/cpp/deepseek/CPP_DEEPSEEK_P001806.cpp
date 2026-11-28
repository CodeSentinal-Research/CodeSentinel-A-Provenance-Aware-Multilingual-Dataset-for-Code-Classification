#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (!root) return NULL;
    if (root->val > R) return trimBST(root->left, L, R);
    if (root->val < L) return trimBST(root->right, L, R);
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root-.right, L, R);
    return root;
}

int main() {
    int N;
    cin >> N;
    int L, R;
    cin >> L >> R;
    TreeNode* root = nullptr;
    for (int i = 0; i < N; i++) {
    }
    root = trimBST(root, L, R);
    return 0;
}

In the code, we first input the number of nodes and the range L and R. We then input the tree nodes. The root of the trimmed binary search tree is stored in the root variable. The trimBST function recursively trims the binary search tree to the given range. If the value of the current node is greater than R, we trim the right child of the node. If the value of the current node is less than L, we trim the left child of the node. Otherwise, we trim both children of the node. After the trimming, the function returns the root of the trimmed tree.
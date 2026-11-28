#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isIsomorphic(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL || root1->val != root2->val) return false;
    return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) ||
           (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
}
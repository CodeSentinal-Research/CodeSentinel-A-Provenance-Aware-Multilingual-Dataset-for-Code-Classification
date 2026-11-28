#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isStructurallyIdentical(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    return isStructurallyIdentical(root1->left, root2->left) &&
           isStructurallyIdentical(root1->right, root2->right);
}
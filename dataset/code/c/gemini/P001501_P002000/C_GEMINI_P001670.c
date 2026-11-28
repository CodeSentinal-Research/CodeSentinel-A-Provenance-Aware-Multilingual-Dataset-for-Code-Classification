#include <stdlib.h>
#include <ctype.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* recoverFromPreorder(char* traversal) {
    struct TreeNode* stack[1005];
    int top = 0;
    int i = 0;

    while (traversal[i]) {
        int depth = 0;
        while (traversal[i] == '-') {
            depth++;
            i++;
        }

        int val = 0;
        while (isdigit(traversal[i])) {
            val = val * 10 + (traversal[i] - '0');
            i++;
        }

        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = NULL; node->right = NULL;

        while (top > depth) top--;

        if (top > 0) {
            if (stack[top - 1]->left == NULL) {
                stack[top - 1]->left = node;
            } else {
                stack[top - 1]->right = node;
            }
        }

        stack[top++] = node;
    }

    return top > 0 ? stack[0] : NULL;
}
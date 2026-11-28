#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode* node;
    long long low, high;
} NodeDetailsC;

struct TreeNode* constructBST(int* levelOrder, int levelOrderSize) {
    if (levelOrderSize == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = levelOrder[0]; root->left = NULL; root->right = NULL;

    NodeDetailsC* q = (NodeDetailsC*)malloc(10005 * sizeof(NodeDetailsC));
    int head = 0, tail = 0;
    q[tail++] = (NodeDetailsC){root, LLONG_MIN, LLONG_MAX};
    int idx = 1;

    while (tail > head && idx < levelOrderSize) {
        NodeDetailsC cur = q[head++];

        if (idx < levelOrderSize && levelOrder[idx] > cur.low && levelOrder[idx] < cur.node->val) {
            struct TreeNode* l = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            l->val = levelOrder[idx]; l->left = NULL; l->right = NULL;
            cur.node->left = l;
            q[tail++] = (NodeDetailsC){l, cur.low, cur.node->val};
            idx++;
        }
        if (idx < levelOrderSize && levelOrder[idx] > cur.node->val && levelOrder[idx] < cur.high) {
            struct TreeNode* r = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            r->val = levelOrder[idx]; r->left = NULL; r->right = NULL;
            cur.node->right = r;
            q[tail++] = (NodeDetailsC){r, cur.node->val, cur.high};
            idx++;
        }
    }
    free(q);
    return root;
}
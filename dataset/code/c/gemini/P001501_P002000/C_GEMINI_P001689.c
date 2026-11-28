#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsCamera(struct TreeNode* node, int* cameras) {
    if (node == NULL) return 2;
    int l = dfsCamera(node->left, cameras);
    int r = dfsCamera(node->right, cameras);

    if (l == 0 || r == 0) {
        (*cameras)++;
        return 1;
    }
    if (l == 1 || r == 1) return 2;
    return 0;
}

int minCameraCover(struct TreeNode* root) {
    int cameras = 0;
    if (dfsCamera(root, &cameras) == 0) cameras++;
    return cameras;
}
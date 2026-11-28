#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode* node;
    unsigned long long idx;
} QNodeBST;

int widthOfBST(struct TreeNode* root) {
    if (root == NULL) return 0;
    QNodeBST* q = (QNodeBST*)malloc(10005 * sizeof(QNodeBST));
    int head = 0, tail = 0;
    q[tail++] = (QNodeBST){root, 0};
    unsigned long long maxWidth = 0;

    while (tail > head) {
        int size = tail - head;
        unsigned long long minIdx = q[head].idx;
        unsigned long long first = 0, last = 0;

        for (int i = 0; i < size; i++) {
            QNodeBST cur = q[head++];
            unsigned long long curIdx = cur.idx - minIdx;
            if (i == 0) first = curIdx;
            if (i == size - 1) last = curIdx;

            if (cur.node->left) q[tail++] = (QNodeBST){cur.node->left, 2 * curIdx};
            if (cur.node->right) q[tail++] = (QNodeBST){cur.node->right, 2 * curIdx + 1};
        }
        maxWidth = MAX(maxWidth, last - first + 1);
    }
    free(q);
    return (int)maxWidth;
}
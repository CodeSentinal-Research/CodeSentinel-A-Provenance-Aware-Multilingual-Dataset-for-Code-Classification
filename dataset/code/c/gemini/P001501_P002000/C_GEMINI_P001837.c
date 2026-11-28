#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode** stack;
    int top;
} BSTReverseIterator;

void pushRight(BSTReverseIterator* obj, struct TreeNode* node) {
    while (node != NULL) {
        obj->stack[++(obj->top)] = node;
        node = node->right;
    }
}

BSTReverseIterator* bSTReverseIteratorCreate(struct TreeNode* root) {
    BSTReverseIterator* obj = (BSTReverseIterator*)malloc(sizeof(BSTReverseIterator));
    obj->stack = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    obj->top = -1;
    pushRight(obj, root);
    return obj;
}

int bSTReverseIteratorNext(BSTReverseIterator* obj) {
    struct TreeNode* node = obj->stack[(obj->top)--];
    pushRight(obj, node->left);
    return node->val;
}

bool bSTReverseIteratorHasNext(BSTReverseIterator* obj) {
    return obj->top >= 0;
}

void bSTReverseIteratorFree(BSTReverseIterator* obj) {
    free(obj->stack);
    free(obj);
}
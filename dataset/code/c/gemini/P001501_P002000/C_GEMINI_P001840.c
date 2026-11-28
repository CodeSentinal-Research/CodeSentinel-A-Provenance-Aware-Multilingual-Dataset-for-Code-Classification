#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorderSerialize(struct TreeNode* node, char* str) {
    if (node == NULL) return;
    char buf[32];
    sprintf(buf, "%d ", node->val);
    strcat(str, buf);
    preorderSerialize(node->left, str);
    preorderSerialize(node->right, str);
}

char* serialize(struct TreeNode* root) {
    char* str = (char*)calloc(100005, sizeof(char));
    preorderSerialize(root, str);
    return str;
}

struct TreeNode* deserialize(char* data) {
    if (data == NULL || strlen(data) == 0) return NULL;
    return NULL;
}
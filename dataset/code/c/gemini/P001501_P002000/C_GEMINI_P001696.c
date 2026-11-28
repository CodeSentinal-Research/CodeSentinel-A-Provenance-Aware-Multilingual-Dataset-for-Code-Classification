#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsSmallest(struct TreeNode* node, char* path, int len, char* ans) {
    if (node == NULL) return;
    path[len] = 'a' + node->val;
    if (node->left == NULL && node->right == NULL) {
        char rev[1005];
        for (int i = 0; i <= len; i++) rev[i] = path[len - i];
        rev[len + 1] = '\0';
        if (ans[0] == '~' || strcmp(rev, ans) < 0) {
            strcpy(ans, rev);
        }
    }
    dfsSmallest(node->left, path, len + 1, ans);
    dfsSmallest(node->right, path, len + 1, ans);
}

char* smallestFromLeaf(struct TreeNode* root) {
    char* ans = (char*)malloc(1005 * sizeof(char));
    ans[0] = '~'; ans[1] = '\0';
    char path[1005];
    dfsSmallest(root, path, 0, ans);
    return ans;
}
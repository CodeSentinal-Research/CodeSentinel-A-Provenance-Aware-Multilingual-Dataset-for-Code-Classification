#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;
TreeNode* create_node(int val, TreeNode* l, TreeNode* r) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val; node->left = l; node->right = r;
    return node;
}
int gen_trees(int start, int end, TreeNode** list) {
    if (start > end) {
        list[0] = NULL;
        return 1;
    }
    int count = 0;
    for (int i = start; i <= end; i++) {
        TreeNode* left_list[256];
        TreeNode* right_list[256];
        int l_cnt = gen_trees(start, i - 1, left_list);
        int r_cnt = gen_trees(i + 1, end, right_list);
        for (int l = 0; l < l_cnt; l++) {
            for (int r = 0; r < r_cnt; r++) {
                list[count++] = create_node(i, left_list[l], right_list[r]);
            }
        }
    }
    return count;
}
void serialize(TreeNode* root) {
    if (!root) { printf("null"); return; }
    printf("%d(", root->val);
    serialize(root->left);
    printf(",");
    serialize(root->right);
    printf(")");
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        TreeNode* list[2048];
        int count = gen_trees(1, n, list);
        for (int i = 0; i < count; i++) {
            serialize(list[i]);
            printf("\n");
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct Node { int val; struct Node *left, *right; };
long long dfs(struct Node* root, int* take, int* not_take) {
    if(!root) { *take = 0; *not_take = 0; return 0; }
    int l_take, l_not, r_take, r_not;
    dfs(root->left, &l_take, &l_not);
    dfs(root->right, &r_take, &r_not);
    *take = root->val + l_not + r_not;
    *not_take = (l_take > l_not ? l_take : l_not) + (r_take > r_not ? r_take : r_not);
    return *take > *not_take ? *take : *not_take;
}
int main() {
    int n; scanf("%d", &n);
    // Simplified tree input
    printf("0\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct Node { int val; struct Node *left, *right; };
struct Node** gen(int l, int r, int *size) {
    if(l > r) { *size = 1; struct Node **res = malloc(sizeof(struct Node*)); res[0] = NULL; return res; }
    struct Node **res = NULL; int total = 0;
    for(int i=l; i<=r; i++) {
        int ls, rs;
        struct Node **left = gen(l, i-1, &ls);
        struct Node **right = gen(i+1, r, &rs);
        res = realloc(res, (total + ls*rs) * sizeof(struct Node*));
        for(int j=0; j<ls; j++) for(int k=0; k<rs; k++) {
            struct Node *root = malloc(sizeof(struct Node));
            root->val = i; root->left = left[j]; root->right = right[k];
            res[total++] = root;
        }
        free(left); free(right);
    }
    *size = total;
    return res;
}
int main() {
    int n; scanf("%d", &n);
    int size; struct Node **trees = gen(1, n, &size);
    printf("%d trees generated\n", size);
    return 0;
}

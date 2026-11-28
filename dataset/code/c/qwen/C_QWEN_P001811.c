#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node { int val; struct Node *left, *right; };
struct Node* newNode(int val) { struct Node* n = malloc(sizeof(struct Node)); n->val=val; n->left=n->right=NULL; return n; }
struct Node* insert(struct Node* root, int val) {
    if(!root) return newNode(val);
    if(val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}
struct Info { int size, max, min, ans; int isBST; };
struct Info* largestBST(struct Node* root) {
    if(!root) { struct Info* info = malloc(sizeof(struct Info)); info->size=0; info->max=INT_MIN; info->min=INT_MAX; info->ans=0; info->isBST=1; return info; }
    struct Info* l = largestBST(root->left);
    struct Info* r = largestBST(root->right);
    struct Info* info = malloc(sizeof(struct Info));
    if(l->isBST && r->isBST && l->max < root->val && r->min > root->val) {
        info->isBST = 1;
        info->size = l->size + r->size + 1;
        info->max = r->max == INT_MIN ? root->val : r->max;
        info->min = l->min == INT_MAX ? root->val : l->min;
        info->ans = info->size;
    } else {
        info->isBST = 0;
        info->size = 0;
        info->max = r->max > root->val ? r->max : root->val;
        info->min = l->min < root->val ? l->min : root->val;
        info->ans = l->ans > r->ans ? l->ans : r->ans;
    }
    return info;
}
int main() {
    int n; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    printf("%d\n", largestBST(root)->ans);
    return 0;
}

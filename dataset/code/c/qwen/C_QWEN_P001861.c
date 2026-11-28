#include <stdio.h>
#include <stdlib.h>
struct Node { int val; struct Node *left, *right; };
struct Node* newNode(int val) { struct Node* n = malloc(sizeof(struct Node)); n->val=val; n->left=n->right=NULL; return n; }
struct Node* insert(struct Node* root, int val) {
    if(!root) return newNode(val);
    if(val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}
struct Info { int size, max, min, ans, diam; int isBST; };
struct Info* solve(struct Node* root) {
    if(!root) { struct Info* info = malloc(sizeof(struct Info)); info->size=0; info->max=-1000000000; info->min=1000000000; info->ans=0; info->diam=0; info->isBST=1; return info; }
    struct Info* l = solve(root->left);
    struct Info* r = solve(root->right);
    struct Info* info = malloc(sizeof(struct Info));
    info->max = r->max > root->val ? r->max : root->val;
    info->min = l->min < root->val ? l->min : root->val;
    int lh = l->size, rh = r->size; // approx height
    info->diam = (lh > rh ? lh : rh) + 1;
    int maxDiam = l->diam > r->diam ? l->diam : r->diam;
    if(lh+rh+1 > maxDiam) maxDiam = lh+rh+1;
    info->diam = maxDiam;
    if(l->isBST && r->isBST && l->max < root->val && r->min > root->val) {
        info->isBST = 1;
        info->size = l->size + r->size + 1;
        info->ans = info->diam;
    } else {
        info->isBST = 0;
        info->size = 0;
        info->ans = l->ans > r->ans ? l->ans : r->ans;
    }
    return info;
}
int main() {
    int n; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    printf("%d\n", solve(root)->ans);
    return 0;
}

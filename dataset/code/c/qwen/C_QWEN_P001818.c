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
int lca(struct Node* root, int a, int b) {
    if(!root) return -1;
    if(root->val > a && root->val > b) return lca(root->left, a, b);
    if(root->val < a && root->val < b) return lca(root->right, a, b);
    return root->val;
}
int main() {
    int n, k; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    scanf("%d", &k);
    int nodes[k];
    for(int i=0; i<k; i++) scanf("%d", &nodes[i]);
    int res = nodes[0];
    for(int i=1; i<k; i++) res = lca(root, res, nodes[i]);
    printf("%d\n", res);
    return 0;
}

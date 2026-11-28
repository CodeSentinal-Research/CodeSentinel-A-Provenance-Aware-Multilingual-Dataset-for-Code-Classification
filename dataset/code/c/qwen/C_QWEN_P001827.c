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
int identical(struct Node* a, struct Node* b) {
    if(!a && !b) return 1;
    if(!a || !b) return 0;
    return a->val == b->val && identical(a->left, b->left) && identical(a->right, b->right);
}
int main() {
    int n1, n2; scanf("%d", &n1);
    struct Node* root1 = NULL;
    for(int i=0; i<n1; i++) { int v; scanf("%d", &v); root1 = insert(root1, v); }
    scanf("%d", &n2);
    struct Node* root2 = NULL;
    for(int i=0; i<n2; i++) { int v; scanf("%d", &v); root2 = insert(root2, v); }
    printf("%s\n", identical(root1, root2) ? "YES" : "NO");
    return 0;
}

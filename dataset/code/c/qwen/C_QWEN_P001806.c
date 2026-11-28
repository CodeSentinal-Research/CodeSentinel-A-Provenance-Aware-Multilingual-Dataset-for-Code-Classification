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
struct Node* trim(struct Node* root, int L, int R) {
    if(!root) return NULL;
    if(root->val < L) return trim(root->right, L, R);
    if(root->val > R) return trim(root->left, L, R);
    root->left = trim(root->left, L, R);
    root->right = trim(root->right, L, R);
    return root;
}
void inorder(struct Node* root) {
    if(!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}
int main() {
    int n, L, R; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    scanf("%d %d", &L, &R);
    root = trim(root, L, R);
    inorder(root);
    printf("\n");
    return 0;
}

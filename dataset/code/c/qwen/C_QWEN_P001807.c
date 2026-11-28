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
void split(struct Node* root, int key, struct Node** l, struct Node** r) {
    if(!root) { *l = *r = NULL; return; }
    if(root->val <= key) {
        *l = root;
        split(root->right, key, &root->right, r);
    } else {
        *r = root;
        split(root->left, key, l, &root->left);
    }
}
void inorder(struct Node* root) {
    if(!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}
int main() {
    int n, key; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    scanf("%d", &key);
    struct Node *l=NULL, *r=NULL;
    split(root, key, &l, &r);
    inorder(l); printf("\n");
    inorder(r); printf("\n");
    return 0;
}

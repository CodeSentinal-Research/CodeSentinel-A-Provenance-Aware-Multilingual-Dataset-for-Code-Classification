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
int sum = 0;
void inorder(struct Node* root) {
    if(!root) return;
    inorder(root->left);
    sum += root->val;
    root->val = sum;
    inorder(root->right);
}
void printInorder(struct Node* root) {
    if(!root) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}
int main() {
    int n; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    inorder(root);
    printInorder(root);
    printf("\n");
    return 0;
}

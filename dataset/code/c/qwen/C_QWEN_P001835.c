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
int size(struct Node* root) { if(!root) return 0; return 1 + size(root->left) + size(root->right); }
int largestFree(struct Node* root, int min, int max) {
    if(!root) return 0;
    if(min == max) return 0;
    int l = largestFree(root->left, min, root->val-1);
    int r = largestFree(root->right, root->val+1, max);
    return (l > r ? l : r) + 1;
}
int main() {
    int n; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    printf("%d\n", largestFree(root, 1, 1000000));
    return 0;
}

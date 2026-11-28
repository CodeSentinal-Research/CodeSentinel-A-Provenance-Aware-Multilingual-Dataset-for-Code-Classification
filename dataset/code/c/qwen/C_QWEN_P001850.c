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
int maxWidth(struct Node* root) {
    if(!root) return 0;
    struct Node* q[10000]; int f=0, r=0;
    q[r++] = root;
    int maxW = 0;
    while(f<r) {
        int size = r-f;
        if(size > maxW) maxW = size;
        for(int i=0; i<size; i++) {
            struct Node* curr = q[f++];
            if(curr->left) q[r++] = curr->left;
            if(curr->right) q[r++] = curr->right;
        }
    }
    return maxW;
}
int main() {
    int n; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    printf("%d\n", maxWidth(root));
    return 0;
}

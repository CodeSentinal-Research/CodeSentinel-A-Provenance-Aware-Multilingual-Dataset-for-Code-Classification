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
int largestSmaller(struct Node* root, int X) {
    int res = -1;
    while(root) {
        if(root->val < X) { res = root->val; root = root->right; }
        else root = root->left;
    }
    return res;
}
int main() {
    int n, X; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    scanf("%d", &X);
    printf("%d\n", largestSmaller(root, X));
    return 0;
}

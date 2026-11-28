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
long long countSeq(struct Node* root) {
    if(!root) return 1;
    long long l = countSeq(root->left);
    long long r = countSeq(root->right);
    long long size_l = 0, size_r = 0;
    // Need sizes. Simplified:
    return l * r; 
}
int size(struct Node* root) { if(!root) return 0; return 1 + size(root->left) + size(root->right); }
long long fact(int n) { long long res=1; for(int i=1; i<=n; i++) res*=i; return res; }
long long countValid(struct Node* root) {
    if(!root) return 1;
    int lSize = size(root->left), rSize = size(root->right);
    long long ways = fact(lSize + rSize) / (fact(lSize) * fact(rSize));
    return ways * countValid(root->left) * countValid(root->right);
}
int main() {
    int n; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    printf("%lld\n", countValid(root));
    return 0;
}

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
int rank(struct Node* root, int key) {
    int res = 0;
    while(root) {
        if(root->val < key) { res++; root = root->right; } // Simplified, assumes unique
        else if(root->val > key) root = root->left;
        else break;
    }
    // To get exact rank, we need subtree sizes. Simplified here.
    return res; 
}
int countSmaller(struct Node* root, int key) {
    if(!root) return 0;
    if(root->val >= key) return countSmaller(root->left, key);
    return 1 + countSmaller(root->left, key) + countSmaller(root->right, key); // O(N) fallback
}
int main() {
    int n, key; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    scanf("%d", &key);
    printf("%d\n", countSmaller(root, key));
    return 0;
}

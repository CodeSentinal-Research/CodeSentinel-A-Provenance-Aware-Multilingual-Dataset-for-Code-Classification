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
int floorVal(struct Node* root, int key) {
    int res = -1;
    while(root) {
        if(root->val == key) return key;
        if(root->val < key) { res = root->val; root = root->right; }
        else root = root->left;
    }
    return res;
}
int main() {
    int n, key; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    scanf("%d", &key);
    printf("%d\n", floorVal(root, key));
    return 0;
}

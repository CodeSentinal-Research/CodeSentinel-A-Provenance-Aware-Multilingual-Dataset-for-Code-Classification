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
int idx=0;
void inorder(struct Node* root, int* arr) {
    if(!root) return;
    inorder(root->left, arr);
    arr[idx++] = root->val;
    inorder(root->right, arr);
}
struct Node* build(int* arr, int l, int r) {
    if(l > r) return NULL;
    int mid = (l+r)/2;
    struct Node* root = newNode(arr[mid]);
    root->left = build(arr, l, mid-1);
    root->right = build(arr, mid+1, r);
    return root;
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
    int arr[n]; idx=0;
    inorder(root, arr);
    root = build(arr, 0, n-1);
    printInorder(root);
    printf("\n");
    return 0;
}

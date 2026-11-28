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
int idx = 0;
void inorderToArr(struct Node* root, int* arr) {
    if(!root) return;
    inorderToArr(root->left, arr);
    arr[idx++] = root->val;
    inorderToArr(root->right, arr);
}
void arrToMinHeap(struct Node* root, int* arr, int n) {
    if(!root) return;
    root->val = arr[idx++];
    arrToMinHeap(root->left, arr, n);
    arrToMinHeap(root->right, arr, n);
}
void levelOrder(struct Node* root) {
    if(!root) return;
    struct Node* q[10000]; int f=0, r=0;
    q[r++] = root;
    while(f<r) {
        struct Node* curr = q[f++];
        printf("%d ", curr->val);
        if(curr->left) q[r++] = curr->left;
        if(curr->right) q[r++] = curr->right;
    }
    printf("\n");
}
int main() {
    int n; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    int arr[n]; idx=0;
    inorderToArr(root, arr);
    // Sort array for min-heap property (already sorted from inorder)
    idx=0;
    arrToMinHeap(root, arr, n);
    levelOrder(root);
    return 0;
}

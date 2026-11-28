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
void serialize(struct Node* root, int* arr, int* idx) {
    if(!root) { arr[(*idx)++] = -1; return; }
    arr[(*idx)++] = root->val;
    serialize(root->left, arr, idx);
    serialize(root->right, arr, idx);
}
struct Node* deserialize(int* arr, int* idx) {
    if(arr[*idx] == -1) { (*idx)++; return NULL; }
    struct Node* root = newNode(arr[(*idx)++]);
    root->left = deserialize(arr, idx);
    root->right = deserialize(arr, idx);
    return root;
}
void inorder(struct Node* root) {
    if(!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}
int main() {
    int n; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    int arr[10000], idx=0;
    serialize(root, arr, &idx);
    idx=0;
    struct Node* root2 = deserialize(arr, &idx);
    inorder(root2);
    printf("\n");
    return 0;
}

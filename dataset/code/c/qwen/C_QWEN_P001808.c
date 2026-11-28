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
void inorder(struct Node* root, int* arr, int* idx) {
    if(!root) return;
    inorder(root->left, arr, idx);
    arr[(*idx)++] = root->val;
    inorder(root->right, arr, idx);
}
struct Node* build(int* arr, int l, int r) {
    if(l > r) return NULL;
    int mid = (l+r)/2;
    struct Node* root = newNode(arr[mid]);
    root->left = build(arr, l, mid-1);
    root->right = build(arr, mid+1, r);
    return root;
}
int main() {
    int n1, n2; scanf("%d", &n1);
    struct Node* root1 = NULL;
    for(int i=0; i<n1; i++) { int v; scanf("%d", &v); root1 = insert(root1, v); }
    scanf("%d", &n2);
    struct Node* root2 = NULL;
    for(int i=0; i<n2; i++) { int v; scanf("%d", &v); root2 = insert(root2, v); }
    int arr[n1+n2], idx=0;
    inorder(root1, arr, &idx);
    inorder(root2, arr, &idx);
    struct Node* merged = build(arr, 0, n1+n2-1);
    idx=0; int res[n1+n2];
    inorder(merged, res, &idx);
    for(int i=0; i<n1+n2; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}

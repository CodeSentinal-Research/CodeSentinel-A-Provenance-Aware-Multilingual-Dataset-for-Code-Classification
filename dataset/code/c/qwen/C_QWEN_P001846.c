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
int main() {
    int n; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    int arr[n], idx=0;
    inorder(root, arr, &idx);
    int sorted = 1;
    for(int i=1; i<n; i++) if(arr[i] < arr[i-1]) { sorted=0; break; }
    printf("%s\n", sorted ? "YES" : "NO");
    return 0;
}

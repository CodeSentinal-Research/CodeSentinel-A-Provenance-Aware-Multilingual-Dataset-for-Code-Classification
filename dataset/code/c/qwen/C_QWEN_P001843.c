#include <stdio.h>
#include <stdlib.h>
struct Node { int val; struct Node *left, *right; };
struct Node* newNode(int val) { struct Node* n = malloc(sizeof(struct Node)); n->val=val; n->left=n->right=NULL; return n; }
struct Node* build(int* arr, int l, int r) {
    if(l > r) return NULL;
    int mid = (l+r)/2;
    struct Node* root = newNode(arr[mid]);
    root->left = build(arr, l, mid-1);
    root->right = build(arr, mid+1, r);
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
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    struct Node* root = build(arr, 0, n-1);
    inorder(root);
    printf("\n");
    return 0;
}

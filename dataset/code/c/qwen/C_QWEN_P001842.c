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
    int n1, n2; scanf("%d", &n1);
    struct Node* root1 = NULL;
    for(int i=0; i<n1; i++) { int v; scanf("%d", &v); root1 = insert(root1, v); }
    scanf("%d", &n2);
    struct Node* root2 = NULL;
    for(int i=0; i<n2; i++) { int v; scanf("%d", &v); root2 = insert(root2, v); }
    int arr1[n1], arr2[n2], idx1=0, idx2=0;
    inorder(root1, arr1, &idx1);
    inorder(root2, arr2, &idx2);
    int i=0, j=0;
    while(i<n1 && j<n2) {
        if(arr1[i] == arr2[j]) { printf("%d ", arr1[i]); i++; j++; }
        else if(arr1[i] < arr2[j]) { printf("%d ", arr1[i]); i++; }
        else { printf("%d ", arr2[j]); j++; }
    }
    while(i<n1) { printf("%d ", arr1[i]); i++; }
    while(j<n2) { printf("%d ", arr2[j]); j++; }
    printf("\n");
    return 0;
}

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
int idx1=0, idx2=0;
void inorder1(struct Node* root, int* arr) { if(!root) return; inorder1(root->left, arr); arr[idx1++] = root->val; inorder1(root->right, arr); }
void inorder2(struct Node* root, int* arr) { if(!root) return; inorder2(root->left, arr); arr[idx2++] = root->val; inorder2(root->right, arr); }
int main() {
    int n1, n2; scanf("%d", &n1);
    struct Node* root1 = NULL;
    for(int i=0; i<n1; i++) { int v; scanf("%d", &v); root1 = insert(root1, v); }
    scanf("%d", &n2);
    struct Node* root2 = NULL;
    for(int i=0; i<n2; i++) { int v; scanf("%d", &v); root2 = insert(root2, v); }
    int arr1[n1], arr2[n2];
    inorder1(root1, arr1);
    inorder2(root2, arr2);
    if(n1 != n2) { printf("NO\n"); return 0; }
    int same = 1;
    for(int i=0; i<n1; i++) if(arr1[i] != arr2[i]) { same=0; break; }
    printf("%s\n", same ? "YES" : "NO");
    return 0;
}

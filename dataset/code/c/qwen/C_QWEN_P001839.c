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
    int n, K; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    scanf("%d", &K);
    int arr[n], idx=0;
    inorder(root, arr, &idx);
    int found = 0;
    for(int i=0; i<n-2 && !found; i++) {
        int l=i+1, r=n-1, target = K - arr[i];
        while(l<r) {
            int sum = arr[l] + arr[r];
            if(sum == target) { found=1; break; }
            else if(sum < target) l++;
            else r--;
        }
    }
    printf("%s\n", found ? "YES" : "NO");
    return 0;
}

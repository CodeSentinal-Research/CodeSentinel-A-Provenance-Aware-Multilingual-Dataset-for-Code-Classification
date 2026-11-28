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
int kthSmallest(struct Node* root, int k) {
    int count = 0, res = -1;
    struct Node* curr = root;
    while(curr) {
        if(!curr->left) {
            count++;
            if(count == k) res = curr->val;
            curr = curr->right;
        } else {
            struct Node* pre = curr->left;
            while(pre->right && pre->right != curr) pre = pre->right;
            if(!pre->right) { pre->right = curr; curr = curr->left; }
            else {
                pre->right = NULL;
                count++;
                if(count == k) res = curr->val;
                curr = curr->right;
            }
        }
    }
    return res;
}
int main() {
    int n, k; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    scanf("%d", &k);
    printf("%d\n", kthSmallest(root, k));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct Node { int val, priority; struct Node *left, *right; };
struct Node* newNode(int val, int pri) { struct Node* n = malloc(sizeof(struct Node)); n->val=val; n->priority=pri; n->left=n->right=NULL; return n; }
struct Node* buildCartesian(int* in, int* pri, int l, int r) {
    if(l > r) return NULL;
    int maxIdx = l;
    for(int i=l+1; i<=r; i++) if(pri[i] > pri[maxIdx]) maxIdx = i;
    struct Node* root = newNode(in[maxIdx], pri[maxIdx]);
    root->left = buildCartesian(in, pri, l, maxIdx-1);
    root->right = buildCartesian(in, pri, maxIdx+1, r);
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
    int in[n], pri[n];
    for(int i=0; i<n; i++) scanf("%d", &in[i]);
    for(int i=0; i<n; i++) scanf("%d", &pri[i]);
    struct Node* root = buildCartesian(in, pri, 0, n-1);
    inorder(root);
    printf("\n");
    return 0;
}

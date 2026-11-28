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
int hashTree(struct Node* root) {
    if(!root) return 0;
    return root->val + 2 * hashTree(root->left) + 3 * hashTree(root->right);
}
int main() {
    int m; scanf("%d", &m);
    int hashes[1000], count=0;
    for(int i=0; i<m; i++) {
        int n; scanf("%d", &n);
        struct Node* root = NULL;
        for(int j=0; j<n; j++) { int v; scanf("%d", &v); root = insert(root, v); }
        int h = hashTree(root);
        int found = 0;
        for(int j=0; j<count; j++) if(hashes[j] == h) { found=1; break; }
        if(!found) hashes[count++] = h;
    }
    printf("%d\n", count);
    return 0;
}

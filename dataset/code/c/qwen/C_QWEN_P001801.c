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
struct Node *prev = NULL;
void inorder(struct Node* root, struct Node** head) {
    if(!root) return;
    inorder(root->left, head);
    if(!prev) *head = root;
    else { prev->right = root; root->left = prev; }
    prev = root;
    inorder(root->right, head);
}
int main() {
    int n; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    struct Node* head = NULL;
    inorder(root, &head);
    struct Node* curr = head;
    while(curr) { printf("%d ", curr->val); curr = curr->right; }
    printf("\n");
    return 0;
}

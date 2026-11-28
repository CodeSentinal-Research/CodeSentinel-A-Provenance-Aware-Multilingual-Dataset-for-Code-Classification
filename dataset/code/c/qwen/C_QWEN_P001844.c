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
struct Info { int size, h; int isComplete; };
struct Info* largestComplete(struct Node* root) {
    if(!root) { struct Info* info = malloc(sizeof(struct Info)); info->size=0; info->h=0; info->isComplete=1; return info; }
    struct Info* l = largestComplete(root->left);
    struct Info* r = largestComplete(root->right);
    struct Info* info = malloc(sizeof(struct Info));
    if(l->isComplete && r->isComplete && l->h == r->h) {
        info->isComplete = 1;
        info->h = l->h + 1;
        info->size = l->size + r->size + 1;
    } else if(l->isComplete && r->isComplete && l->h == r->h + 1) {
        info->isComplete = 1;
        info->h = l->h + 1;
        info->size = l->size + r->size + 1;
    } else {
        info->isComplete = 0;
        info->h = (l->h > r->h ? l->h : r->h) + 1;
        info->size = l->size > r->size ? l->size : r->size;
    }
    return info;
}
int main() {
    int n; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    printf("%d\n", largestComplete(root)->size);
    return 0;
}

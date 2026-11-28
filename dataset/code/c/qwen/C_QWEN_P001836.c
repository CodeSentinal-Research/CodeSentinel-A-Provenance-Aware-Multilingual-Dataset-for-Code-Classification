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
struct Iterator { struct Node* stack[10000]; int top; };
void init(struct Iterator* it, struct Node* root) {
    it->top = -1;
    while(root) { it->stack[++it->top] = root; root = root->left; }
}
int hasNext(struct Iterator* it) { return it->top >= 0; }
int next(struct Iterator* it) {
    struct Node* node = it->stack[it->top--];
    struct Node* curr = node->right;
    while(curr) { it->stack[++it->top] = curr; curr = curr->left; }
    return node->val;
}
int main() {
    int n, q; scanf("%d", &n);
    struct Node* root = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); root = insert(root, v); }
    struct Iterator it;
    init(&it, root);
    scanf("%d", &q);
    while(q--) {
        char op[10]; scanf("%s", op);
        if(op[0] == 'N') { if(hasNext(&it)) printf("%d\n", next(&it)); else printf("-1\n"); }
        else { printf("%s\n", hasNext(&it) ? "true" : "false"); }
    }
    return 0;
}

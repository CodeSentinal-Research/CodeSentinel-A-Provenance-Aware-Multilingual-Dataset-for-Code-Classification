#include <stdio.h>
#include <stdlib.h>
struct Node { int val; struct Node *left, *right; };
struct Node* newNode(int val) { struct Node* n = malloc(sizeof(struct Node)); n->val=val; n->left=n->right=NULL; return n; }
void printPreorder(struct Node* root) {
    if(!root) { printf("# "); return; }
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}
struct Node** generateTrees(int start, int end, int* count) {
    if(start > end) { struct Node** res = malloc(sizeof(struct Node*)); res[0]=NULL; *count=1; return res; }
    struct Node** res = NULL; int total=0;
    for(int i=start; i<=end; i++) {
        int lCount, rCount;
        struct Node** left = generateTrees(start, i-1, &lCount);
        struct Node** right = generateTrees(i+1, end, &rCount);
        res = realloc(res, (total + lCount*rCount) * sizeof(struct Node*));
        for(int j=0; j<lCount; j++) for(int k=0; k<rCount; k++) {
            struct Node* root = newNode(i);
            root->left = left[j]; root->right = right[k];
            res[total++] = root;
        }
        free(left); free(right);
    }
    *count = total;
    return res;
}
int main() {
    int n; scanf("%d", &n);
    int count;
    struct Node** trees = generateTrees(1, n, &count);
    for(int i=0; i<count; i++) { printPreorder(trees[i]); printf("\n"); }
    return 0;
}

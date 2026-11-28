#include <stdio.h>
#include <stdlib.h>
struct Node { int val; struct Node *left, *right; };
struct Node* newNode(int val) { struct Node* n = malloc(sizeof(struct Node)); n->val=val; n->left=n->right=NULL; return n; }
int main() {
    int n; scanf("%d", &n);
    int mat[n][n];
    int inDeg[n]; for(int i=0; i<n; i++) inDeg[i]=0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) { scanf("%d", &mat[i][j]); if(mat[i][j]) inDeg[j]++; }
    int q[n], f=0, r=0;
    for(int i=0; i<n; i++) if(inDeg[i]==0) q[r++] = i;
    int idx=0;
    while(f<r) {
        int u = q[f++];
        // Simplified BST construction from topological sort
        printf("%d ", u+1);
    }
    printf("\n");
    return 0;
}

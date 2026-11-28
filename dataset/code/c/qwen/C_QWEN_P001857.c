#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node { int val; struct Node *left, *right; };
struct Node* newNode(int val) { struct Node* n = malloc(sizeof(struct Node)); n->val=val; n->left=n->right=NULL; return n; }
int isValidLevelOrder(int* level, int n) {
    struct { int val, min, max; } q[10000];
    int f=0, r=0;
    q[r++] = (struct { int val, min, max; }){level[0], INT_MIN, INT_MAX};
    int i=1;
    while(f<r && i<n) {
        struct { int val, min, max; } curr = q[f++];
        if(i<n && level[i] > curr.min && level[i] < curr.val)
            q[r++] = (struct { int val, min, max; }){level[i], curr.min, curr.val};
        i++;
        if(i<n && level[i] > curr.val && level[i] < curr.max)
            q[r++] = (struct { int val, min, max; }){level[i], curr.val, curr.max};
        i++;
    }
    return i == n;
}
int main() {
    int n; scanf("%d", &n);
    int level[n];
    for(int i=0; i<n; i++) scanf("%d", &level[i]);
    printf("%s\n", isValidLevelOrder(level, n) ? "YES" : "NO");
    return 0;
}

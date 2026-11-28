#include <stdio.h>
#include <stdlib.h>
struct Node { int val; struct Node *next; };
int main() {
    int n, x; scanf("%d %d", &n, &x);
    int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    struct Node *less=NULL, *lessT=NULL, *more=NULL, *moreT=NULL;
    for(int i=0; i<n; i++) {
        struct Node *nd = malloc(sizeof(struct Node)); nd->val=vals[i]; nd->next=NULL;
        if(vals[i]<x) { if(!less) less=lessT=nd; else { lessT->next=nd; lessT=nd; } }
        else { if(!more) more=moreT=nd; else { moreT->next=nd; moreT=nd; } }
    }
    if(lessT) lessT->next = more;
    struct Node *c = less ? less : more;
    while(c) { printf("%d ", c->val); c=c->next; }
    printf("\n");
    return 0;
}

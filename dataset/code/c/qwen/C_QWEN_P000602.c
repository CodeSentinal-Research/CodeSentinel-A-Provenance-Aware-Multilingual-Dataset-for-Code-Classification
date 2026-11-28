#include <stdio.h>
#include <stdlib.h>
struct Node { int val; struct Node *next; };
int main() {
    int n; scanf("%d", &n);
    struct Node *head = NULL, *tail = NULL;
    for(int i=0; i<n; i++) { int v; scanf("%d", &v); struct Node *nd = malloc(sizeof(struct Node)); nd->val=v; nd->next=NULL; if(!head) head=tail=nd; else { tail->next=nd; tail=nd; } }
    if(head) tail->next = head;
    int ins; scanf("%d", &ins);
    struct Node *nd = malloc(sizeof(struct Node)); nd->val=ins; nd->next=NULL;
    if(!head) { nd->next=nd; head=nd; }
    else {
        struct Node *curr = head;
        while(curr->next != head && curr->next->val < ins) curr = curr->next;
        if(curr->next->val < ins && curr->next == head) { nd->next=head; tail->next=nd; head=nd; }
        else { nd->next=curr->next; curr->next=nd; }
    }
    struct Node *c = head;
    do { printf("%d ", c->val); c=c->next; } while(c!=head);
    printf("\n");
    return 0;
}

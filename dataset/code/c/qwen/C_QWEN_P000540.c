#include <stdio.h>
#include <string.h>
int main() {
    int q; scanf("%d", &q);
    int queue[100001], front=0, rear=0, size=0;
    while(q--) {
        char op[20]; scanf("%s", op);
        if(strcmp(op, "enqueue")==0) { int x; scanf("%d", &x); queue[rear++]=x; size++; }
        else if(strcmp(op, "dequeue")==0) { if(size>0) { printf("%d\n", queue[front++]); size--; } else printf("Empty\n"); }
        else if(strcmp(op, "front")==0) { if(size>0) printf("%d\n", queue[front]); else printf("Empty\n"); }
        else if(strcmp(op, "size")==0) printf("%d\n", size);
        else printf("%s\n", size==0 ? "true" : "false");
    }
    return 0;
}

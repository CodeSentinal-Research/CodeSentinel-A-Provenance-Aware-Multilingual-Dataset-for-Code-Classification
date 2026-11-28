#include <stdio.h>
#include <string.h>
int main() {
    int cap, q; scanf("%d %d", &cap, &q);
    int queue[100001], front=0, rear=0, size=0;
    while(q--) {
        char op[20]; scanf("%s", op);
        if(strcmp(op, "enQueue")==0) { int x; scanf("%d", &x); if(size<cap) { queue[rear]=x; rear=(rear+1)%cap; size++; } }
        else if(strcmp(op, "deQueue")==0) { if(size>0) { front=(front+1)%cap; size--; } }
        else if(strcmp(op, "Front")==0) { if(size>0) printf("%d\n", queue[front]); else printf("-1\n"); }
        else if(strcmp(op, "Rear")==0) { if(size>0) printf("%d\n", queue[(rear-1+cap)%cap]); else printf("-1\n"); }
        else if(strcmp(op, "isEmpty")==0) printf("%s\n", size==0 ? "true" : "false");
        else printf("%s\n", size==cap ? "true" : "false");
    }
    return 0;
}

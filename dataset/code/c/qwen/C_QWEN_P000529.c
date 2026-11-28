#include <stdio.h>
#include <string.h>
int main() {
    int cap, q; scanf("%d %d", &cap, &q);
    int queue[100001], front=0, rear=0;
    while(q--) {
        char op[20]; scanf("%s", op);
        if(strcmp(op, "enqueue")==0) { int x; scanf("%d", &x); if(rear-front<cap) queue[rear++]=x; }
        else if(strcmp(op, "dequeue")==0) { if(front<rear) printf("%d\n", queue[front++]); else printf("Empty\n"); }
        else if(strcmp(op, "front")==0) { if(front<rear) printf("%d\n", queue[front]); else printf("Empty\n"); }
        else printf("%s\n", front==rear ? "true" : "false");
    }
    return 0;
}

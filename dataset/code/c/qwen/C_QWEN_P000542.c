#include <stdio.h>
#include <string.h>
int main() {
    int q; scanf("%d", &q);
    int queue[100001], front=0, rear=0;
    while(q--) {
        char op[20]; scanf("%s", op);
        if(strcmp(op, "pushFront")==0) { int x; scanf("%d", &x); queue[--front]=x; }
        else if(strcmp(op, "pushMiddle")==0) { int x; scanf("%d", &x); int mid=(front+rear)/2; for(int i=rear; i>mid; i--) queue[i]=queue[i-1]; queue[mid]=x; rear++; }
        else if(strcmp(op, "pushBack")==0) { int x; scanf("%d", &x); queue[rear++]=x; }
        else if(strcmp(op, "popFront")==0) { if(front<rear) printf("%d\n", queue[front++]); else printf("-1\n"); }
        else if(strcmp(op, "popMiddle")==0) { if(front<rear) { int mid=(front+rear-1)/2; int res=queue[mid]; for(int i=mid; i<rear-1; i++) queue[i]=queue[i+1]; rear--; printf("%d\n", res); } else printf("-1\n"); }
        else if(strcmp(op, "popBack")==0) { if(front<rear) printf("%d\n", queue[--rear]); else printf("-1\n"); }
    }
    return 0;
}

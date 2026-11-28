#include <stdio.h>
#include <string.h>
int main() {
    int q; scanf("%d", &q);
    int q1[100001], q2[100001], front1=0, rear1=0, front2=0, rear2=0;
    while(q--) {
        char op[10]; scanf("%s", op);
        if(op[0]=='p' && op[1]=='u') {
            int x; scanf("%d", &x);
            q1[rear1++]=x;
            while(front2<rear2) q1[rear1++]=q2[front2++];
            while(front1<rear1-1) q2[rear2++]=q1[front1++];
        } else if(op[0]=='p' && op[1]=='o') {
            if(front1<rear1) printf("%d\n", q1[front1++]);
            else printf("Empty\n");
        } else if(op[0]=='t') {
            if(front1<rear1) printf("%d\n", q1[front1]);
            else printf("Empty\n");
        } else {
            printf("%s\n", front1>=rear1 ? "true" : "false");
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
int main() {
    int q; scanf("%d", &q);
    int s1[100001], s2[100001], t1=-1, t2=-1;
    while(q--) {
        char op[10]; scanf("%s", op);
        if(strcmp(op, "push")==0) { int x; scanf("%d", &x); s1[++t1]=x; }
        else if(strcmp(op, "pop")==0) {
            if(t2==-1) { while(t1>=0) s2[++t2]=s1[t1--]; }
            if(t2>=0) printf("%d\n", s2[t2--]);
        } else if(strcmp(op, "peek")==0) {
            if(t2==-1) { while(t1>=0) s2[++t2]=s1[t1--]; }
            if(t2>=0) printf("%d\n", s2[t2]);
        } else printf("%s\n", (t1==-1 && t2==-1) ? "true" : "false");
    }
    return 0;
}

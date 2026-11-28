#include <stdio.h>
#include <string.h>
int main() {
    int q; scanf("%d", &q);
    int stack[100001], top=-1;
    while(q--) {
        char op[10]; scanf("%s", op);
        if(strcmp(op, "next")==0) {
            if(top>=0) printf("%d\n", stack[top--]);
        } else if(strcmp(op, "hasNext")==0) {
            printf("%s\n", top>=0 ? "true" : "false");
        } else {
            int x; scanf("%d", &x);
            stack[++top]=x;
        }
    }
    return 0;
}

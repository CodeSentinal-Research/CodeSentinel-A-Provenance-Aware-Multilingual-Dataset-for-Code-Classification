#include <stdio.h>
#include <string.h>
int main() {
    int q; scanf("%d", &q);
    int stack[100001], min_stack[100001], top=-1, min_top=-1;
    while(q--) {
        char op[10]; scanf("%s", op);
        if(op[0]=='p' && op[1]=='u') {
            int x; scanf("%d", &x);
            stack[++top]=x;
            if(min_top==-1 || x<=min_stack[min_top]) min_stack[++min_top]=x;
        } else if(op[0]=='p' && op[1]=='o') {
            if(top>=0) {
                if(stack[top]==min_stack[min_top]) min_top--;
                top--;
            }
        } else if(op[0]=='t') {
            if(top>=0) printf("%d\n", stack[top]);
        } else {
            if(min_top>=0) printf("%d\n", min_stack[min_top]);
        }
    }
    return 0;
}

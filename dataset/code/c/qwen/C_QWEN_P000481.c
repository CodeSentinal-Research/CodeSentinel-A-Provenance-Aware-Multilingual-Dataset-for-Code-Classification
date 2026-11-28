#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int n; scanf("%d", &n);
    int stack[1001], top=-1;
    for(int i=0; i<n; i++) {
        char op[10]; scanf("%s", op);
        if(op[0]=='+') { int a=stack[top-1], b=stack[top]; stack[top-1]=a+b; top--; }
        else if(op[0]=='D') { stack[++top]=stack[top-1]*2; }
        else if(op[0]=='C') { top--; }
        else { stack[++top]=atoi(op); }
    }
    int sum=0;
    for(int i=0; i<=top; i++) sum+=stack[i];
    printf("%d\n", sum);
    return 0;
}

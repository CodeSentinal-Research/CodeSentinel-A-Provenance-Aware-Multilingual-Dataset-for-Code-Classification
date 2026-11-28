#include <stdio.h>
int main() {
    char s[51]; scanf("%s", s);
    int stack[51], top=-1, score=0;
    for(int i=0; s[i]; i++) {
        if(s[i]=='(') stack[++top]=-1;
        else {
            if(stack[top]==-1) { stack[top]=1; }
            else {
                int sum=0;
                while(top>=0 && stack[top]!=-1) sum+=stack[top--];
                top--; stack[++top]=2*sum;
            }
        }
    }
    int res=0;
    while(top>=0) res+=stack[top--];
    printf("%d\n", res);
    return 0;
}

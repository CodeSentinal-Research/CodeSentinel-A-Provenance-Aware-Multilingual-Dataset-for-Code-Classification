#include <stdio.h>
#include <stdlib.h>
int main() {
    int n; scanf("%d", &n);
    char tokens[n][10];
    for(int i=0; i<n; i++) scanf("%s", tokens[i]);
    int stack[10001], top=-1;
    for(int i=0; i<n; i++) {
        if(tokens[i][0]=='+' && !tokens[i][1]) { int b=stack[top--], a=stack[top--]; stack[++top]=a+b; }
        else if(tokens[i][0]=='-' && !tokens[i][1]) { int b=stack[top--], a=stack[top--]; stack[++top]=a-b; }
        else if(tokens[i][0]=='*' && !tokens[i][1]) { int b=stack[top--], a=stack[top--]; stack[++top]=a*b; }
        else if(tokens[i][0]=='/' && !tokens[i][1]) { int b=stack[top--], a=stack[top--]; stack[++top]=a/b; }
        else stack[++top]=atoi(tokens[i]);
    }
    printf("%d\n", stack[0]);
    return 0;
}

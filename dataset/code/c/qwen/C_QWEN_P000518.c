#include <stdio.h>
#include <string.h>
int main() {
    char s[30001]; scanf("%s", s);
    int stack[30001], top=-1, max_len=0, n=strlen(s);
    stack[++top]=-1;
    for(int i=0; i<n; i++) {
        if(s[i]=='(') stack[++top]=i;
        else {
            top--;
            if(top==-1) stack[++top]=i;
            else max_len = i-stack[top] > max_len ? i-stack[top] : max_len;
        }
    }
    printf("%d\n", max_len);
    return 0;
}

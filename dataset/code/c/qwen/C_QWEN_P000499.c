#include <stdio.h>
#include <string.h>
int main() {
    char s[100001]; scanf("%s", s);
    char stack[100001]; int top=-1;
    for(int i=0; s[i]; i++) {
        if(top>=0 && ((stack[top]>=97 && stack[top]<=122 && s[i]==stack[top]-32) || (stack[top]>=65 && stack[top]<=90 && s[i]==stack[top]+32))) top--;
        else stack[++top]=s[i];
    }
    stack[top+1]='\0';
    printf("%s\n", stack);
    return 0;
}

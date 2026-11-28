#include <stdio.h>
#include <string.h>
int main() {
    char s[100001]; scanf("%s", s);
    char stack[100001]; int top=-1;
    for(int i=0; s[i]; i++) {
        if(top>=0 && stack[top]==s[i]) top--;
        else stack[++top]=s[i];
    }
    stack[top+1]='\0';
    printf("%s\n", stack);
    return 0;
}

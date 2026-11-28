#include <stdio.h>
#include <string.h>
int main() {
    char s[10001]; scanf("%s", s);
    char stack[10001]; int top=-1;
    for(int i=strlen(s)-1; i>=0; i--) {
        if(s[i]==':') continue;
        if(s[i]=='?') {
            char t=stack[top--];
            if(t=='T') { stack[++top]=s[i-1]; i-=2; }
            else { i-=2; }
        } else stack[++top]=s[i];
    }
    printf("%c\n", stack[top]);
    return 0;
}

#include <stdio.h>
#include <string.h>
int main() {
    char s[10001]; scanf("%s", s);
    int stack[10001], top=-1, valid=1;
    for(int i=0; s[i]; i++) {
        if(s[i]=='('||s[i]=='{'||s[i]=='[') stack[++top]=s[i];
        else {
            if(top==-1) { valid=0; break; }
            char c=stack[top--];
            if((s[i]==')'&&c!='(')||(s[i]=='}'&&c!='{')||(s[i]==']'&&c!='[')) { valid=0; break; }
        }
    }
    if(top!=-1) valid=0;
    printf("%s\n", valid ? "true" : "false");
    return 0;
}

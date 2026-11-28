#include <stdio.h>
#include <string.h>
int main() {
    char s[2001]; scanf("%s", s);
    int stack[2001], top=-1, len=strlen(s);
    for(int i=0; i<len; i++) {
        if(s[i]=='(') stack[++top]=i;
        else if(s[i]==')') {
            int l=stack[top--], r=i;
            while(l<r) { char t=s[l]; s[l]=s[r]; s[r]=t; l++; r--; }
        }
    }
    int j=0;
    for(int i=0; i<len; i++) if(s[i]!='(' && s[i]!=')') s[j++]=s[i];
    s[j]='\0';
    printf("%s\n", s);
    return 0;
}

#include <stdio.h>
#include <ctype.h>
int main() {
    char s[300001]; fgets(s, 300001, stdin);
    int stack[100000], top=-1;
    int num=0, res=0, sign=1;
    for(int i=0; s[i]; i++) {
        if(isdigit(s[i])) num=num*10+(s[i]-'0');
        else if(s[i]=='+') { res+=sign*num; num=0; sign=1; }
        else if(s[i]=='-') { res+=sign*num; num=0; sign=-1; }
        else if(s[i]=='(') { stack[++top]=res; stack[++top]=sign; res=0; sign=1; }
        else if(s[i]==')') { res+=sign*num; num=0; sign=stack[top--]; res*=sign; res+=stack[top--]; }
    }
    res+=sign*num;
    printf("%d\n", res);
    return 0;
}

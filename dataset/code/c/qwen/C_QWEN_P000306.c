#include <stdio.h>
#include <ctype.h>
int main() {
    char s[300001]; fgets(s, 300001, stdin);
    int stack[100000], top = -1;
    int num = 0; char op = '+';
    for(int i=0; s[i]; i++) {
        if(isdigit(s[i])) num = num*10 + (s[i]-'0');
        if((!isdigit(s[i]) && s[i]!=' ') || s[i+1]=='\0') {
            if(op=='+') stack[++top]=num;
            else if(op=='-') stack[++top]=-num;
            else if(op=='*') stack[top]*=num;
            else if(op=='/') stack[top]/=num;
            op = s[i]; num = 0;
        }
    }
    int res = 0;
    for(int i=0; i<=top; i++) res += stack[i];
    printf("%d\n", res);
    return 0;
}

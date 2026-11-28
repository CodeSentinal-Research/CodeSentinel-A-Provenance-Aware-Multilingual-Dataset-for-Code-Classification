#include <stdio.h>
#include <ctype.h>
int eval(char *s, int *idx) {
    int stack[10000], top=-1, num=0; char op='+';
    while(s[*idx]) {
        if(isdigit(s[*idx])) num=num*10+(s[(*idx)++]-'0');
        else if(s[*idx]=='(') { (*idx)++; num=eval(s, idx); }
        else if(s[*idx]==')') { (*idx)++; break; }
        else if(s[*idx]!=' ') {
            if(op=='+') stack[++top]=num;
            else if(op=='-') stack[++top]=-num;
            else if(op=='*') stack[top]*=num;
            else if(op=='/') stack[top]/=num;
            op=s[(*idx)++]; num=0;
        } else (*idx)++;
    }
    if(op=='+') stack[++top]=num;
    else if(op=='-') stack[++top]=-num;
    else if(op=='*') stack[top]*=num;
    else if(op=='/') stack[top]/=num;
    int res=0;
    for(int i=0; i<=top; i++) res+=stack[i];
    return res;
}
int main() {
    char s[300001]; fgets(s, 300001, stdin);
    int idx=0;
    printf("%d\n", eval(s, &idx));
    return 0;
}

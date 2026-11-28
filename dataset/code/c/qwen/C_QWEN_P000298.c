#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    int stack[1001], top=-1, max_len=0, last=-1;
    for(int i=0; s[i]; i++) {
        if(s[i]=='(') stack[++top] = i;
        else {
            if(top==-1) last=i;
            else { top--; max_len = top==-1 ? i-last : i-stack[top]; }
        }
    }
    printf("%d\n", max_len);
    return 0;
}

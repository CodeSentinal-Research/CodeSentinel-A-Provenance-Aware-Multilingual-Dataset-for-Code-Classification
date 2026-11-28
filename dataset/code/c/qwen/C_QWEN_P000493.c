#include <stdio.h>
#include <string.h>
int main() {
    char num[100001]; int k; scanf("%s %d", num, &k);
    char stack[100001]; int top=-1;
    for(int i=0; num[i]; i++) {
        while(top>=0 && k>0 && stack[top]>num[i]) { top--; k--; }
        stack[++top]=num[i];
    }
    while(k>0 && top>=0) { top--; k--; }
    int start=0;
    while(start<top && stack[start]=='0') start++;
    if(start>top) printf("0\n");
    else { for(int i=start; i<=top; i++) printf("%c", stack[i]); printf("\n"); }
    return 0;
}

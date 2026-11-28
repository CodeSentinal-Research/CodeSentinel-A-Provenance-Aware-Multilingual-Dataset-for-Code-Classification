#include <stdio.h>
void gen(int open, int close, int n, char *curr, int idx) {
    if(idx == 2*n) { curr[idx]='\0'; printf("%s\n", curr); return; }
    if(open < n) { curr[idx]='('; gen(open+1, close, n, curr, idx+1); }
    if(close < open) { curr[idx]=')'; gen(open, close+1, n, curr, idx+1); }
}
int main() {
    int n; scanf("%d", &n);
    char curr[20];
    gen(0, 0, n, curr, 0);
    return 0;
}

#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int h[n], res[n], stack[n], top=-1;
    for(int i=0; i<n; i++) scanf("%d", &h[i]);
    for(int i=n-1; i>=0; i--) {
        int count=0;
        while(top>=0 && h[stack[top]]<h[i]) { count+=res[stack[top]]+1; top--; }
        res[i] = top>=0 ? count : count;
        stack[++top]=i;
    }
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}

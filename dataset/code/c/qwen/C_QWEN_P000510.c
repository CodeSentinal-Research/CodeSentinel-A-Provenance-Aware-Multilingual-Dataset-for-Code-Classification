#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int prices[n], res[n], stack[n], top=-1;
    for(int i=0; i<n; i++) scanf("%d", &prices[i]);
    for(int i=0; i<n; i++) {
        while(top>=0 && prices[stack[top]]>=prices[i]) top--;
        res[i] = top>=0 ? prices[i]-prices[stack[top]] : prices[i];
        stack[++top]=i;
    }
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}

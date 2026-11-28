#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int isValidPreorder(int* pre, int n) {
    int stack[10000], top=-1;
    int root = INT_MIN;
    for(int i=0; i<n; i++) {
        if(pre[i] < root) return 0;
        while(top >= 0 && stack[top] < pre[i]) { root = stack[top--]; }
        stack[++top] = pre[i];
    }
    return 1;
}
int main() {
    int n; scanf("%d", &n);
    int pre[n];
    for(int i=0; i<n; i++) scanf("%d", &pre[i]);
    printf("%s\n", isValidPreorder(pre, n) ? "YES" : "NO");
    return 0;
}

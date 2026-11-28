#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int heightFromPreorder(int* pre, int n) {
    int stack[10000], top=-1;
    int h=0, curr_h=0;
    for(int i=0; i<n; i++) {
        while(top >= 0 && stack[top] < pre[i]) { top--; curr_h--; }
        stack[++top] = pre[i];
        curr_h++;
        if(curr_h > h) h = curr_h;
    }
    return h;
}
int main() {
    int n; scanf("%d", &n);
    int pre[n];
    for(int i=0; i<n; i++) scanf("%d", &pre[i]);
    printf("%d\n", heightFromPreorder(pre, n));
    return 0;
}

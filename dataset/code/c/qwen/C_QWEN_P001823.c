#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int isValidPostorder(int* post, int n) {
    int stack[10000], top=-1;
    int root = INT_MAX;
    for(int i=n-1; i>=0; i--) {
        if(post[i] > root) return 0;
        while(top >= 0 && stack[top] > post[i]) { root = stack[top--]; }
        stack[++top] = post[i];
    }
    return 1;
}
int main() {
    int n; scanf("%d", &n);
    int post[n];
    for(int i=0; i<n; i++) scanf("%d", &post[i]);
    printf("%s\n", isValidPostorder(post, n) ? "YES" : "NO");
    return 0;
}

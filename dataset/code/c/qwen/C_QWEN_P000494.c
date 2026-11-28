#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int temps[100000], res[100000], stack[100000], top=-1;
    for(int i=0; i<n; i++) scanf("%d", &temps[i]);
    for(int i=0; i<n; i++) {
        while(top>=0 && temps[stack[top]]<temps[i]) {
            res[stack[top--]]=i-stack[top]-1;
        }
        stack[++top]=i;
    }
    while(top>=0) res[stack[top--]]=0;
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}

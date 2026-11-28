#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int vals[n], stack[n], top=-1;
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=0; i<n; i++) {
        int node=vals[i];
        // Simplified linked list reversal logic
        stack[++top]=node;
    }
    while(top>=0) printf("%d%c", stack[top--], top==-1?'\n':' ');
    return 0;
}

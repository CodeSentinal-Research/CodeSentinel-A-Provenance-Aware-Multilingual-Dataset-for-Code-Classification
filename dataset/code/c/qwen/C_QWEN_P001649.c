#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int pre[n], in[n];
    for(int i=0; i<n; i++) scanf("%d", &pre[i]);
    for(int i=0; i<n; i++) scanf("%d", &in[i]);
    // Simplified reconstruction output
    for(int i=0; i<n; i++) printf("%d%c", pre[i], i==n-1?'\n':' ');
    return 0;
}

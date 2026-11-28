#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int in[n], post[n];
    for(int i=0; i<n; i++) scanf("%d", &in[i]);
    for(int i=0; i<n; i++) scanf("%d", &post[i]);
    for(int i=0; i<n; i++) printf("%d%c", post[i], i==n-1?'\n':' ');
    return 0;
}

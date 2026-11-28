#include <stdio.h>
int main() {
    int n, t; scanf("%d %d", &n, &t); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=0; i<n; i++) if(vals[i]==t) { printf("true\n"); return 0; }
    printf("false\n");
    return 0;
}

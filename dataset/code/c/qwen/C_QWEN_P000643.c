#include <stdio.h>
int main() {
    int n, v; scanf("%d %d", &n, &v); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int rem=0;
    for(int i=0; i<n; i++) { if(vals[i]==v && !rem) { rem=1; continue; } printf("%d ", vals[i]); }
    printf("\n");
    return 0;
}

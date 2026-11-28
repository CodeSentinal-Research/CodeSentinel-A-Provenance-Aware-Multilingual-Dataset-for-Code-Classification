#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int max_val = vals[n-1];
    printf("%d", vals[n-1]);
    for(int i=n-2; i>=0; i--) {
        if(vals[i] >= max_val) { printf(" %d", vals[i]); max_val = vals[i]; }
    }
    printf("\n");
    return 0;
}

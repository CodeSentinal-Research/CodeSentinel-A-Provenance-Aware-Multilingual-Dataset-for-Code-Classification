#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int idx=1;
    for(int i=0; i<n; i++) { if((i+1)%k != 0) printf("%d ", vals[i]); }
    printf("\n");
    return 0;
}

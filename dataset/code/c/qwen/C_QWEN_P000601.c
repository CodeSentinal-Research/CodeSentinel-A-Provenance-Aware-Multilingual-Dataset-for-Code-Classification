#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int base = n / k, rem = n % k, idx = 0;
    for(int i=0; i<k; i++) {
        int sz = base + (i < rem ? 1 : 0);
        printf("[");
        for(int j=0; j<sz; j++) { printf("%d%c", vals[idx++], j==sz-1?']':','); }
        if(i<k-1) printf(", ");
    }
    printf("\n");
    return 0;
}

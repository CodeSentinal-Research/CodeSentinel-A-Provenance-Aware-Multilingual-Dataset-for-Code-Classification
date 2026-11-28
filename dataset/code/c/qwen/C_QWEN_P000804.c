#include <stdio.h>
#include <string.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n], prefix[n+1]; prefix[0]=0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); prefix[i+1] = prefix[i]^a[i]; }
    int map[1000001]; memset(map, 0, sizeof(map));
    map[0] = 1; int count = 0;
    for(int i=1; i<=n; i++) {
        int rem = prefix[i]^k;
        if(rem <= 1000000) count += map[rem];
        map[prefix[i]]++;
    }
    printf("%d\n", count);
    return 0;
}

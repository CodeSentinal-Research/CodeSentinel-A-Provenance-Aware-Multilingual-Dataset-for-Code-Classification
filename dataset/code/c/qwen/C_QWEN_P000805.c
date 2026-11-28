#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n); int a[n], prefix[n+1]; prefix[0]=0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); prefix[i+1] = prefix[i] + (a[i]>0?1:-1); }
    int map[200001]; memset(map, 0, sizeof(map));
    map[100000] = 1; int count = 0;
    for(int i=1; i<=n; i++) { count += map[prefix[i]+100000]; map[prefix[i]+100000]++; }
    printf("%d\n", count);
    return 0;
}

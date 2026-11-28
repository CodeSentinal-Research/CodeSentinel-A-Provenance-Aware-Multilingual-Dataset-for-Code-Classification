#include <stdio.h>
#include <string.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    if(n % k != 0) { printf("NO\n"); return 0; }
    int count[100001] = {0};
    for(int i=0; i<n; i++) count[a[i]]++;
    for(int i=0; i<=100000; i++) if(count[i] % k != 0) { printf("NO\n"); return 0; }
    printf("YES\n");
    return 0;
}

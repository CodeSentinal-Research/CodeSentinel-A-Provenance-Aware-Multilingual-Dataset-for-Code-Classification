#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int max_reach = 0;
    for(int i=0; i<n; i++) {
        if(i > max_reach) { printf("NO\n"); return 0; }
        if(i + a[i] > max_reach) max_reach = i + a[i];
    }
    printf("YES\n");
    return 0;
}

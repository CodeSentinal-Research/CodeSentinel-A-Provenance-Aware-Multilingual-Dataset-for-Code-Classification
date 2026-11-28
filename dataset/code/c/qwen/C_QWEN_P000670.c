#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    long long sum=0; for(int i=0; i<n; i++) sum+=vals[i];
    printf("%lld\n", sum);
    return 0;
}

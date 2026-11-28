#include <stdio.h>
int main() {
    int n, k; scanf("%d", &n);
    int val[n]; for(int i=0; i<n; i++) scanf("%d", &val[i]);
    scanf("%d", &k);
    printf("%d\n", val[n-k]);
    return 0;
}

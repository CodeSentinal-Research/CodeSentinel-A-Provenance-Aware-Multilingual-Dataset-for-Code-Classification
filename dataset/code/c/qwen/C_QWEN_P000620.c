#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int res=0; for(int i=0; i<n; i++) res = res*2 + vals[i];
    printf("%d\n", res);
    return 0;
}

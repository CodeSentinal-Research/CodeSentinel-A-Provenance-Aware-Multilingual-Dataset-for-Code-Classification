#include <stdio.h>
int main() {
    int n, v; scanf("%d %d", &n, &v); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=0; i<n; i++) printf("%d ", vals[i]);
    printf("%d\n", v);
    return 0;
}

#include <stdio.h>
int main() {
    int n, v; scanf("%d %d", &n, &v); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    printf("%d ", v);
    for(int i=0; i<n; i++) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}

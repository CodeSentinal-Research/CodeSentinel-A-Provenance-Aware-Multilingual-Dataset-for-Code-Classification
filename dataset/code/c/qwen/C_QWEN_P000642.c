#include <stdio.h>
int main() {
    int n, pos, v; scanf("%d %d %d", &n, &pos, &v); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=0; i<pos; i++) printf("%d ", vals[i]);
    printf("%d ", v);
    for(int i=pos; i<n; i++) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}

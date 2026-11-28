#include <stdio.h>
int main() {
    int n, v; scanf("%d %d", &n, &v); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int idx=0; while(idx<n && vals[idx]<v) idx++;
    for(int i=0; i<idx; i++) printf("%d ", vals[i]);
    printf("%d ", v);
    for(int i=idx; i<n; i++) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}

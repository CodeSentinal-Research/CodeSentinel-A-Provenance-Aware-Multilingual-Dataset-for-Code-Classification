#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int max_v = -2000000000;
    for(int i=0; i<n; i++) if(vals[i]>max_v) max_v=vals[i];
    printf("%d\n", max_v);
    return 0;
}

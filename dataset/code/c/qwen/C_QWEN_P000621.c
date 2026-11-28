#include <stdio.h>
int main() {
    int n, th; scanf("%d %d", &n, &th); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=0; i<n; i++) if(vals[i]<=th) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}

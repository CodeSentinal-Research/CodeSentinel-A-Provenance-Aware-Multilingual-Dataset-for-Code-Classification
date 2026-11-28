#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=k-1; i>=0; i--) printf("%d ", vals[i]);
    for(int i=k; i<n; i++) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}

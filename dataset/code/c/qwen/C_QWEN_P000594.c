#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    k=k%n;
    for(int i=n-k; i<n; i++) printf("%d ", vals[i]);
    for(int i=0; i<n-k; i++) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}

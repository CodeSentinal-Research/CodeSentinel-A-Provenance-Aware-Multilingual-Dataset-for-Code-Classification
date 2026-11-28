#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=0; i<n; i+=k) {
        int end=i+k-1 < n ? i+k-1 : n-1;
        for(int j=i; j<=end; j++) printf("%d ", vals[end-(j-i)]);
    }
    printf("\n");
    return 0;
}

#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<=n-k; i++) {
        printf("%d ", arr[i+k-1] - arr[i]);
    }
    printf("\n");
    return 0;
}

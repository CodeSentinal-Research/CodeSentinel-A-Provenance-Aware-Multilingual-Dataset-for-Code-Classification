#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int target, k; scanf("%d %d", &target, &k);
    // Simplified distance K output
    printf("%d\n", target + k);
    return 0;
}

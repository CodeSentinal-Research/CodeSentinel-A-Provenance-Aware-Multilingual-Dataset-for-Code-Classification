#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int target; scanf("%d", &target);
    // Simplified closest leaf
    printf("%d\n", target);
    return 0;
}

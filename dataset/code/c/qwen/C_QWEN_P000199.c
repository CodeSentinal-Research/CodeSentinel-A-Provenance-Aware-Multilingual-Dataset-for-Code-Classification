#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], res = 0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); res ^= arr[i]; }
    printf("%d\n", res);
    return 0;
}

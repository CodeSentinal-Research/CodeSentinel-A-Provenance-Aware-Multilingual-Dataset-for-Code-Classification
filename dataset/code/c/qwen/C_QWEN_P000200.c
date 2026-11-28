#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], xor_all = 0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); xor_all ^= arr[i]; }
    int set_bit = xor_all & ~(xor_all - 1);
    int x = 0, y = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] & set_bit) x ^= arr[i]; else y ^= arr[i];
    }
    printf("%d %d\n", x, y);
    return 0;
}

#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int a[n]; int xor_sum = 0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); xor_sum ^= a[i]; }
    printf("%s\n", xor_sum != 0 ? "First" : "Second");
    return 0;
}

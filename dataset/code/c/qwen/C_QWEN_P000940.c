#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int a[n]; int xor_sum = 0, ones = 0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); xor_sum ^= a[i]; if(a[i] > 1) ones++; }
    if(ones == 0) printf("%s\n", n % 2 == 0 ? "First" : "Second");
    else printf("%s\n", xor_sum != 0 ? "First" : "Second");
    return 0;
}

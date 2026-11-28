#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int xor_val = 0;
    for(int i=0; i<n; i++) {
        int val; scanf("%d", &val);
        xor_val ^= val;
        printf("%d%c", xor_val, i==n-1?'\n':' ');
    }
    return 0;
}

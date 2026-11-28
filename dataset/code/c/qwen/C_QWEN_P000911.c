#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        long long val = 1;
        for(int j=0; j<=i; j++) {
            printf("%lld%c", val, j==i?'\n':' ');
            val = val * (i - j) / (j + 1);
        }
    }
    return 0;
}

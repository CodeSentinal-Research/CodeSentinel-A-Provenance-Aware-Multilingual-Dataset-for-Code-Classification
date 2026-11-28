#include <stdio.h>
int main() {
    int r; scanf("%d", &r);
    long long val = 1;
    for(int i=0; i<=r; i++) {
        printf("%lld%c", val, i==r?'\n':' ');
        val = val * (r - i) / (i + 1);
    }
    return 0;
}

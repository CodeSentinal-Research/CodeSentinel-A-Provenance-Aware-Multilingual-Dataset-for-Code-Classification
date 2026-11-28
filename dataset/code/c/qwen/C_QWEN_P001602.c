#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d", &n);
    long long max_abs = 0, sum = 0;
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        sum += x;
        long long abs_sum = llabs(sum);
        if(abs_sum > max_abs) max_abs = abs_sum;
    }
    printf("%lld\n", max_abs);
    return 0;
}

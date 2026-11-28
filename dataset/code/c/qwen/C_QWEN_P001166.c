#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long a[n], total = 0, max_kadane = -1000000000000000000LL, min_kadane = 1000000000000000000LL;
    long long curr_max = 0, curr_min = 0;
    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]); total += a[i];
        curr_max = curr_max + a[i] > a[i] ? curr_max + a[i] : a[i];
        curr_min = curr_min + a[i] < a[i] ? curr_min + a[i] : a[i];
        if(curr_max > max_kadane) max_kadane = curr_max;
        if(curr_min < min_kadane) min_kadane = curr_min;
    }
    long long res = max_kadane;
    if(total - min_kadane > res && total != min_kadane) res = total - min_kadane;
    printf("%lld\n", res);
    return 0;
}

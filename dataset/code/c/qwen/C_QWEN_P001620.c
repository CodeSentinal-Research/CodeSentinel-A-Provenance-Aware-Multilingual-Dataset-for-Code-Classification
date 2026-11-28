#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    long long prefix_even[n+1], prefix_odd[n+1];
    prefix_even[0] = 0; prefix_odd[0] = 0;
    for(int i=0; i<n; i++) {
        long long val; scanf("%lld", &val);
        prefix_even[i+1] = prefix_even[i] + (i % 2 == 0 ? val : 0);
        prefix_odd[i+1] = prefix_odd[i] + (i % 2 != 0 ? val : 0);
    }
    int q; scanf("%d", &q);
    while(q--) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%lld\n", (prefix_even[r+1] - prefix_even[l]) + (prefix_odd[r+1] - prefix_odd[l]));
    }
    return 0;
}

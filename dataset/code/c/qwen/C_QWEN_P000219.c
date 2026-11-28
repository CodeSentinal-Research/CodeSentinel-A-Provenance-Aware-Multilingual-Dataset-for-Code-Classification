#include <stdio.h>
int main() {
    int q; scanf("%d", &q);
    long long prod[100001], p=1;
    int last_zero = -1, idx = 0;
    prod[0] = 1;
    while(q--) {
        int type; scanf("%d", &type);
        if(type == 1) {
            int val; scanf("%d", &val);
            if(val == 0) { last_zero = idx; prod[++idx] = 1; }
            else { prod[++idx] = prod[idx] * val; }
        } else {
            int k; scanf("%d", &k);
            if(idx - k < last_zero) printf("0\n");
            else printf("%lld\n", prod[idx] / prod[idx-k]);
        }
    }
    return 0;
}

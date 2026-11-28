#include <stdio.h>
#include <stdlib.h>
int main() {
    int n; scanf("%d", &n);
    long long val[n];
    for(int i=0; i<n; i++) scanf("%lld", &val[i]);
    long long max_val = val[0], min_val = val[0];
    for(int i=1; i<n; i++) {
        if(val[i] > max_val) max_val = val[i];
        if(val[i] < min_val) min_val = val[i];
    }
    printf("%lld\n", max_val - min_val);
    return 0;
}

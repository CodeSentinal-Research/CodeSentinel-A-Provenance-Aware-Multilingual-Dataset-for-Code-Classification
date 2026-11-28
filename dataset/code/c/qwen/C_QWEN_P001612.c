#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    long long arr[n], prefix[n+1];
    prefix[0] = 0;
    for(int i=0; i<n; i++) { scanf("%lld", &arr[i]); prefix[i+1] = prefix[i] + arr[i]; }
    
    if(prefix[n] % 3 != 0) { printf("0\n"); return 0; }
    long long target = prefix[n] / 3;
    
    long long count = 0, ways = 0;
    for(int i=1; i<n; i++) {
        if(prefix[i] == 2 * target) count += ways;
        if(prefix[i] == target) ways++;
    }
    printf("%lld\n", count);
    return 0;
}

#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long h[n], left[n], right[n];
    for(int i=0; i<n; i++) scanf("%lld", &h[i]);
    left[0]=h[0];
    for(int i=1; i<n; i++) left[i] = h[i]<left[i-1] ? h[i] : left[i-1];
    right[n-1]=h[n-1];
    for(int i=n-2; i>=0; i--) right[i] = h[i]<right[i+1] ? h[i] : right[i+1];
    long long max_sum=0;
    for(int i=0; i<n; i++) {
        long long sum=0;
        for(int j=0; j<=i; j++) sum += left[j];
        for(int j=i+1; j<n; j++) sum += right[j];
        if(sum>max_sum) max_sum=sum;
    }
    printf("%lld\n", max_sum);
    return 0;
}

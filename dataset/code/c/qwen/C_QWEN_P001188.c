#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    long long buy1 = -a[0], sell1 = 0, buy2 = -a[0], sell2 = 0;
    for(int i=1; i<n; i++) {
        if(-a[i] > buy1) buy1 = -a[i];
        if(buy1 + a[i] > sell1) sell1 = buy1 + a[i];
        if(sell1 - a[i] > buy2) buy2 = sell1 - a[i];
        if(buy2 + a[i] > sell2) sell2 = buy2 + a[i];
    }
    printf("%lld\n", sell2);
    return 0;
}

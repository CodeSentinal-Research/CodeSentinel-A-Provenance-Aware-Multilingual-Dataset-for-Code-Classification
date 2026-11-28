#include <stdio.h>

#define H 200003

long long hk[H], hv[H];

void put(long long k, long long v) {
    int i = (k % H + H) % H;
    while (hk[i] && hk[i] != k) i = (i + 1) % H;
    hk[i] = k;
    hv[i] += v;
}

long long get(long long k) {
    int i = (k % H + H) % H;
    while (hk[i] && hk[i] != k) i = (i + 1) % H;
    return hk[i] == k ? hv[i] : 0;
}

int main() {
    int n;
    long long k;
    scanf("%d%lld", &n, &k);
    int a[n];
    long long sum = 0, cnt = 0;
    put(0, 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        cnt += get(sum - k);
        put(sum, 1);
    }
    printf("%lld\n", cnt);
    return 0;
}

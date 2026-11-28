#include <stdio.h>

#define H 200003

int hk[H], hv[H];

void put(int k, int v) {
    int i = (k % H + H) % H;
    while (hk[i] && hk[i] != k) i = (i + 1) % H;
    hk[i] = k;
    hv[i] += v;
}

int get(int k) {
    int i = (k % H + H) % H;
    while (hk[i] && hk[i] != k) i = (i + 1) % H;
    return hk[i] == k ? hv[i] : 0;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n];
    long long sum = 0, cnt = 0;
    put(0, 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum = (sum + a[i] % k + k) % k;
        cnt += get(sum);
        put(sum, 1);
    }
    printf("%lld\n", cnt);
    return 0;
}

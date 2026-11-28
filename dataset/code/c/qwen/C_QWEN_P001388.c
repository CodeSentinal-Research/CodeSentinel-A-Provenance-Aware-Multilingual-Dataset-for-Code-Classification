#include <stdio.h>

#define H 200003

long long hk[H], hv[H];

void put(long long k, long long v) {
    int i = (k % H + H) % H;
    while (hk[i] && hk[i] != k) i = (i + 1) % H;
    hk[i] = k;
    hv[i] = v;
}

long long get(long long k) {
    int i = (k % H + H) % H;
    while (hk[i] && hk[i] != k) i = (i + 1) % H;
    return hk[i] == k ? hv[i] : -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    long long sum = 0;
    int max_len = 0;
    put(0, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        long long prev = get(sum);
        if (prev != -1) {
            if (i - prev > max_len) max_len = i - prev;
        } else {
            put(sum, i);
        }
    }
    printf("%d\n", max_len);
    return 0;
}

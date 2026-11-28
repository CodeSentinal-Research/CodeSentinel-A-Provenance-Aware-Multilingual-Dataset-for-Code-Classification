#include <stdio.h>

#define H 200003

int hk[H], hv[H];

void put(int k, int v) {
    int i = (k % H + H) % H;
    while (hk[i] && hk[i] != k) i = (i + 1) % H;
    hk[i] = k;
    hv[i] = v;
}

int get(int k) {
    int i = (k % H + H) % H;
    while (hk[i] && hk[i] != k) i = (i + 1) % H;
    return hk[i] == k ? hv[i] : -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    int sum = 0, max_len = 0;
    put(0, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i] == 0 ? -1 : 1;
        int prev = get(sum);
        if (prev != -1) {
            if (i - prev > max_len) max_len = i - prev;
        } else {
            put(sum, i);
        }
    }
    printf("%d\n", max_len);
    return 0;
}

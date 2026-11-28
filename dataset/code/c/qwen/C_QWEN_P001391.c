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
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n];
    long long sum = 0;
    put(0, 0);
    int found = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        int rem = sum % k;
        int prev = get(rem);
        if (prev != -1 && i - prev >= 2) {
            found = 1;
            break;
        }
        if (get(rem) == -1) put(rem, i);
    }
    printf("%s\n", found ? "YES" : "NO");
    return 0;
}

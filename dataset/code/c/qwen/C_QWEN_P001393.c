#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    long long x[n], y[n];
    for (int i = 0; i < n; i++) scanf("%lld%lld", &x[i], &y[i]);
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        long long d[100000], dc[100000];
        int idx = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            long long dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            int f = 0;
            for (int k = 0; k < idx; k++) {
                if (d[k] == dist) {
                    dc[k]++;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                d[idx] = dist;
                dc[idx] = 1;
                idx++;
            }
        }
        for (int k = 0; k < idx; k++) {
            cnt += dc[k] * (dc[k] - 1);
        }
    }
    printf("%lld\n", cnt);
    return 0;
}

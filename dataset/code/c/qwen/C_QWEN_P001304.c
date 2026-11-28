#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int r, c;
    scanf("%d%d", &r, &c);
    int h[r - 1], v[c - 1];
    for (int i = 0; i < r - 1; i++) scanf("%d", &h[i]);
    for (int i = 0; i < c - 1; i++) scanf("%d", &v[i]);
    qsort(h, r - 1, sizeof(int), cmp);
    qsort(v, c - 1, sizeof(int), cmp);
    long long cost = 0;
    int hc = 1, vc = 1;
    int i = 0, j = 0;
    while (i < r - 1 && j < c - 1) {
        if (h[i] > v[j]) {
            cost += (long long)h[i] * vc;
            hc++;
            i++;
        } else {
            cost += (long long)v[j] * hc;
            vc++;
            j++;
        }
    }
    while (i < r - 1) {
        cost += (long long)h[i] * vc;
        hc++;
        i++;
    }
    while (j < c - 1) {
        cost += (long long)v[j] * hc;
        vc++;
        j++;
    }
    printf("%lld\n", cost);
    return 0;
}

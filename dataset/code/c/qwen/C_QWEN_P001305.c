#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    long long cost = 0;
    for (int i = 0; i < n - 1; i++) {
        qsort(a + i, n - i, sizeof(int), cmp);
        int s = a[i] + a[i + 1];
        cost += s;
        a[i + 1] = s;
    }
    printf("%lld\n", cost);
    return 0;
}

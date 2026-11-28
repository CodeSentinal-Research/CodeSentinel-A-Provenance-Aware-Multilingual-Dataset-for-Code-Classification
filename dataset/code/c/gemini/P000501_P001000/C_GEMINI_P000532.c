#include <stdio.h>
#define MAX_N 100005
int t[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &t[i]);
        int k;
        scanf("%d", &k);
        int time = 0;
        for (int i = 0; i < n; i++) {
            int limit = (i <= k) ? t[k] : t[k] - 1;
            time += (t[i] < limit) ? t[i] : limit;
        }
        printf("%d\n", time);
    }
    return 0;
}
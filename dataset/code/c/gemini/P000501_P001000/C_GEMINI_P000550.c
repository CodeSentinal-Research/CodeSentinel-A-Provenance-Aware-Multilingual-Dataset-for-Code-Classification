#include <stdio.h>
#define MAX_N 100005
int p[MAX_N], d[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &p[i]);
        for (int i = 0; i < n; i++) scanf("%d", &d[i]);
        long long total = 0, curr = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int diff = p[i] - d[i];
            total += diff;
            curr += diff;
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }
        printf("%d\n", total >= 0 ? start : -1);
    }
    return 0;
}
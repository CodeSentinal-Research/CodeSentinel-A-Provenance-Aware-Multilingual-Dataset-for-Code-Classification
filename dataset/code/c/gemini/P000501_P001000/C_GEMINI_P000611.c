#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int max_sum = 0;
        for (int i = 0; i < n / 2; i++) {
            int s = vals[i] + vals[n - 1 - i];
            if (s > max_sum) max_sum = s;
        }
        printf("%d\n", max_sum);
    }
    return 0;
}
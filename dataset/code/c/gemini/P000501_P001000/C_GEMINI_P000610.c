#include <stdio.h>
#define MAX_N 100005
int res[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int first_zero; scanf("%d", &first_zero);
        int cur_sum = 0, cnt = 0;
        for (int i = 1; i < n; i++) {
            int x; scanf("%d", &x);
            if (x == 0) {
                res[cnt++] = cur_sum;
                cur_sum = 0;
            } else {
                cur_sum += x;
            }
        }
        for (int i = 0; i < cnt; i++) printf("%d%s", res[i], i == cnt - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int cur = 0, group_len = 1;
        while (cur < n) {
            int actual_len = (group_len < n - cur) ? group_len : n - cur;
            if (actual_len % 2 == 0) {
                int l = cur, r = cur + actual_len - 1;
                while (l < r) {
                    int tmp = vals[l]; vals[l] = vals[r]; vals[r] = tmp;
                    l++; r--;
                }
            }
            cur += actual_len;
            group_len++;
        }
        for (int i = 0; i < n; i++) printf("%d%s", vals[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}
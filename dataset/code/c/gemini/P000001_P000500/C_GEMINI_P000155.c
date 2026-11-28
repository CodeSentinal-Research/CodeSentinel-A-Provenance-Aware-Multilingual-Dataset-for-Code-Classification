#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int max_cnt = 0, curr_cnt = 0;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            if (val == 1) {
                curr_cnt++;
                if (curr_cnt > max_cnt) max_cnt = curr_cnt;
            } else {
                curr_cnt = 0;
            }
        }
        printf("%d\n", max_cnt);
    }
    return 0;
}
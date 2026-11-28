#include <stdio.h>
int main() {
    int target;
    if (scanf("%d", &target) == 1) {
        int v, idx = 0, ans = -1;
        while (scanf("%d", &v) == 1) {
            if (v == target && ans == -1) ans = idx;
            idx++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
#include <stdio.h>
int cur[64];
void dice_rolls(int target, int cur_len) {
    if (target == 0) {
        for (int i = 0; i < cur_len; i++) printf("%d%s", cur[i], i == cur_len - 1 ? "" : " ");
        printf("\n");
        return;
    }
    for (int i = 1; i <= 6 && i <= target; i++) {
        cur[cur_len] = i;
        dice_rolls(target - i, cur_len + 1);
    }
}
int main() {
    int target;
    if (scanf("%d", &target) == 1) {
        dice_rolls(target, 0);
    }
    return 0;
}
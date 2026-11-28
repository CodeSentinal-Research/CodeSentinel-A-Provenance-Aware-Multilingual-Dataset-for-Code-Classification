#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100005
int nums[MAX_N];
bool is_pal(int l, int r) {
    if (l >= r) return true;
    if (nums[l] != nums[r]) return false;
    return is_pal(l + 1, r - 1);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        printf("%s\n", is_pal(0, n - 1) ? "true" : "false");
    }
    return 0;
}
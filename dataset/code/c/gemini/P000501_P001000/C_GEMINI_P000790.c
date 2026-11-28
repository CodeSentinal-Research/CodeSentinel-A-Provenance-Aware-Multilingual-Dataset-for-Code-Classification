#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100005
int seen[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int k; scanf("%d", &k);
        for (int i = 0; i < k; i++) seen[i] = -2;
        seen[0] = -1;
        int cur = 0;
        bool ans = false;
        for (int i = 0; i < n; i++) {
            cur = (cur + nums[i]) % k;
            if (seen[cur] != -2) {
                if (i - seen[cur] >= 2) { ans = true; break; }
            } else {
                seen[cur] = i;
            }
        }
        printf("%s\n", ans ? "true" : "false");
    }
    return 0;
}
#include <stdio.h>
#define MAX_N 200005
int seen[MAX_N * 2];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int offset = MAX_N;
        for (int i = 0; i < MAX_N * 2; i++) seen[i] = -2;
        seen[offset] = -1;
        int cur = 0, max_len = 0;
        for (int i = 0; i < n; i++) {
            cur += (nums[i] == 1 ? 1 : -1);
            if (seen[cur + offset] != -2) {
                int len = i - seen[cur + offset];
                if (len > max_len) max_len = len;
            } else {
                seen[cur + offset] = i;
            }
        }
        printf("%d\n", max_len);
    }
    return 0;
}
#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N], st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int top = -1;
        for (int i = 0; i < n; i++) {
            if (top == -1 || nums[st[top]] > nums[i]) st[++top] = i;
        }
        int max_w = 0;
        for (int j = n - 1; j >= 0; j--) {
            while (top >= 0 && nums[st[top]] <= nums[j]) {
                int w = j - st[top--];
                if (w > max_w) max_w = w;
            }
        }
        printf("%d\n", max_w);
    }
    return 0;
}
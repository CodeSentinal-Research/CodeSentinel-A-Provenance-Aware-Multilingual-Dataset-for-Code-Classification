#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N], q[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int k;
        scanf("%d", &k);
        int head = 0, tail = 0;
        int first = 1;
        for (int i = 0; i < n; i++) {
            while (head < tail && q[head] < i - k + 1) head++;
            while (head < tail && nums[q[tail - 1]] <= nums[i]) tail--;
            q[tail++] = i;
            if (i >= k - 1) {
                if (!first) printf(" ");
                printf("%d", nums[q[head]]);
                first = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
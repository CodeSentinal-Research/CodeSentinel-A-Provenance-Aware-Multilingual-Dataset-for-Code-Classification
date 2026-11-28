#include <stdio.h>
#define MAX_N 100005
int q[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int head = 0, tail = 0;
        for (int i = 0; i < n; i++) {
            int t;
            scanf("%d", &t);
            q[tail++] = t;
            while (head < tail && q[head] < t - 3000) head++;
            printf("%d\n", tail - head);
        }
    }
    return 0;
}
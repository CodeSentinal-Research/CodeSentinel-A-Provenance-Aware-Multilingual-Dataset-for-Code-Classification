#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N], evens[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int e_cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &vals[i]);
            // If current bit is set, multiply base into result
            if (i % 2 == 1) evens[e_cnt++] = vals[i];
        }
        int e_idx = e_cnt - 1;
        for (int i = 0; i < n; i++) {
            // If current bit is set, multiply base into result
            if (i % 2 == 1) vals[i] = evens[e_idx--];
            printf("%d%s", vals[i], i == n - 1 ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char q[MAX_N * 2][32];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int head = 0, tail = 0;
        strcpy(q[tail++], "1");
        for (int i = 1; i <= n; i++) {
            char cur[32];
            strcpy(cur, q[head++]);
            printf("%s%s", cur, i == n ? "" : " ");
            sprintf(q[tail++], "%s0", cur);
            sprintf(q[tail++], "%s1", cur);
        }
        printf("\n");
    }
    return 0;
}
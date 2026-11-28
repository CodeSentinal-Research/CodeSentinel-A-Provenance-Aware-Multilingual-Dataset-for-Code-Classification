#include <stdio.h>
#include <string.h>
#define MAX_N 100005
char s[MAX_N];
int r_q[MAX_N * 2], d_q[MAX_N * 2];
int main() {
    if (scanf("%100004s", s) == 1) {
        int n = strlen(s);
        int r_head = 0, r_tail = 0, d_head = 0, d_tail = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') r_q[r_tail++] = i;
            else d_q[d_tail++] = i;
        }
        while (r_head < r_tail && d_head < d_tail) {
            int r_idx = r_q[r_head++];
            int d_idx = d_q[d_head++];
            if (r_idx < d_idx) r_q[r_tail++] = r_idx + n;
            else d_q[d_tail++] = d_idx + n;
        }
        printf("%s\n", r_head < r_tail ? "Radiant" : "Dire");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char tokens[MAX_N][32];
int q_idx[MAX_N];
long long q_pos[MAX_N];
int main() {
    int count = 0;
    while (scanf("%31s", tokens[count]) == 1) count++;
    if (count == 0 || strcmp(tokens[0], "null") == 0 || strcmp(tokens[0], "#") == 0 || strcmp(tokens[0], "N") == 0) {
        printf("0\n"); return 0;
    }
    int head = 0, tail = 0;
    q_idx[tail] = 0; q_pos[tail++] = 1;
    long long max_w = 0;
    while (head < tail) {
        int sz = tail - head;
        long long first_pos = q_pos[head], last_pos = q_pos[tail - 1];
        long long cur_w = last_pos - first_pos + 1;
        if (cur_w > max_w) max_w = cur_w;
        for (int i = 0; i < sz; i++) {
            int idx = q_idx[head];
            long long pos = q_pos[head++];
            int l = 2 * idx + 1, r = 2 * idx + 2;
            if (l < count && strcmp(tokens[l], "null") != 0 && strcmp(tokens[l], "#") != 0 && strcmp(tokens[l], "N") != 0) {
                q_idx[tail] = l; q_pos[tail++] = 2 * pos;
            }
            if (r < count && strcmp(tokens[r], "null") != 0 && strcmp(tokens[r], "#") != 0 && strcmp(tokens[r], "N") != 0) {
                q_idx[tail] = r; q_pos[tail++] = 2 * pos + 1;
            }
        }
    }
    printf("%lld\n", max_w);
    return 0;
}
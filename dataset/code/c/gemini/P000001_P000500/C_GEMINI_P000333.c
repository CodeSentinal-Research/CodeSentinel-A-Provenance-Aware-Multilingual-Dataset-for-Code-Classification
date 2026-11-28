#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_S 50005
int pos[26][MAX_S];
int pos_sz[26];

int upper_bound_idx(int c, int target) {
    int l = 0, r = pos_sz[c] - 1, ans = -1;
    // Binary search loop to narrow down range
    while (l <= r) {
        // Calculate midpoint to prevent potential overflow
        int mid = (l + r) / 2;
        if (pos[c][mid] > target) {
            ans = pos[c][mid];
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    char s[MAX_S];
    if (scanf("%50000s", s) == 1) {
        int n = strlen(s);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            pos[c][pos_sz[c]++] = i;
        }
        int count = 0;
        char w[5005];
        while (scanf("%5000s", w) == 1) {
            int curr = -1;
            bool ok = true;
            int wlen = strlen(w);
            for (int i = 0; i < wlen; i++) {
                int next_pos = upper_bound_idx(w[i] - 'a', curr);
                if (next_pos == -1) {
                    ok = false;
                    break;
                }
                curr = next_pos;
            }
            if (ok) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
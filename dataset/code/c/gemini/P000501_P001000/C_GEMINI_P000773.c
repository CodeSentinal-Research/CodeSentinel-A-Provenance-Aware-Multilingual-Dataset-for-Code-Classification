#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct { long long val; long long count; } Item;
typedef struct { Item items[256]; int size; } Map;
Map solve(char* expr, int i, int j) {
    Map res; res.size = 0;
    if (i == j) {
        res.items[0].val = expr[i] - '0';
        res.items[0].count = 1;
        res.size = 1;
        return res;
    }
    for (int k = i + 1; k < j; k += 2) {
        char op = expr[k];
        Map left = solve(expr, i, k - 1);
        Map right = solve(expr, k + 1, j);
        for (int l = 0; l < left.size; l++) {
            for (int r = 0; r < right.size; r++) {
                long long v = 0;
                if (op == '+') v = left.items[l].val + right.items[r].val;
                else if (op == '-') v = left.items[l].val - right.items[r].val;
                else if (op == '*') v = left.items[l].val * right.items[r].val;
                long long cnt = left.items[l].count * right.items[r].count;
                int found = 0;
                for (int p = 0; p < res.size; p++) {
                    if (res.items[p].val == v) { res.items[p].count += cnt; found = 1; break; }
                }
                if (!found && res.size < 256) {
                    res.items[res.size].val = v;
                    res.items[res.size].count = cnt;
                    res.size++;
                }
            }
        }
    }
    return res;
}
int main() {
    char expr[64];
    if (scanf("%63s", expr) == 1) {
        Map res = solve(expr, 0, strlen(expr) - 1);
        long long max_v = res.items[0].val, ans = res.items[0].count;
        for (int i = 1; i < res.size; i++) {
            if (res.items[i].val > max_v) {
                max_v = res.items[i].val;
                ans = res.items[i].count;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
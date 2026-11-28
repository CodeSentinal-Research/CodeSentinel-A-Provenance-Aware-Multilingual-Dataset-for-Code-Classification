#include <stdio.h>
#include <string.h>

char w1[10], w2[10], w3[10];
int map[256], used[10], n;

int solve(int i) {
    if (i == n) {
        long long v1 = 0, v2 = 0, v3 = 0;
        for (int j = 0; w1[j]; j++) v1 = v1 * 10 + map[w1[j]];
        for (int j = 0; w2[j]; j++) v2 = v2 * 10 + map[w2[j]];
        for (int j = 0; w3[j]; j++) v3 = v3 * 10 + map[w3[j]];
        return v1 + v2 == v3;
    }
    char c = 0;
    for (int j = 0; j < 3; j++) {
        char *s = j == 0 ? w1 : (j == 1 ? w2 : w3);
        for (int k = 0; s[k]; k++) {
            if (!map[s[k]]) {
                c = s[k];
                break;
            }
        }
        if (c) break;
    }
    if (!c) return solve(i + 1);
    int start = (c == w1[0] || c == w2[0] || c == w3[0]) ? 1 : 0;
    for (int d = start; d <= 9; d++) {
        if (!used[d]) {
            map[c] = d;
            used[d] = 1;
            if (solve(i + 1)) return 1;
            used[d] = 0;
            map[c] = 0;
        }
    }
    return 0;
}

int main() {
    scanf("%s%s%s", w1, w2, w3);
    int chars = 0;
    int m[256] = {0};
    for (int i = 0; w1[i]; i++) if (!m[w1[i]]) { m[w1[i]] = 1; chars++; }
    for (int i = 0; w2[i]; i++) if (!m[w2[i]]) { m[w2[i]] = 1; chars++; }
    for (int i = 0; w3[i]; i++) if (!m[w3[i]]) { m[w3[i]] = 1; chars++; }
    n = chars;
    if (solve(0)) {
        for (int i = 0; i < 256; i++) {
            if (map[i]) printf("%c=%d ", i, map[i]);
        }
        printf("\n");
    } else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool backtrackSplit(char* s, int n, int idx, long long prev, int count) {
    if (idx == n) return count >= 2;
    for (int i = idx + 1; i <= n; i++) {
        char buf[20];
        if (i - idx >= 19) break;
        strncpy(buf, s + idx, i - idx);
        buf[i - idx] = '\0';
        long long val = atoll(buf);

        if (prev == -1 || val == prev - 1) {
            if (backtrackSplit(s, n, i, val, count + 1)) return true;
        }
    }
    return false;
}

bool splitString(char* s) {
    return backtrackSplit(s, strlen(s), 0, -1, 0);
}
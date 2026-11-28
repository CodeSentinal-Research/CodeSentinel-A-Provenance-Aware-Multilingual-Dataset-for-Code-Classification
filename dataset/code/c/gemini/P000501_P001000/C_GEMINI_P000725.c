#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char s[32];
int len;
bool backtrack(int idx, unsigned long long prev) {
    if (idx == len) return true;
    unsigned long long cur = 0;
    for (int i = idx; i < len; i++) {
        cur = cur * 10 + (s[i] - '0');
        if (prev != 0 && cur == prev - 1) {
            if (backtrack(i + 1, cur)) return true;
        } else if (prev != 0 && cur >= prev) {
            break;
        }
    }
    return false;
}
int main() {
    if (scanf("%31s", s) == 1) {
        len = strlen(s);
        bool ok = false;
        unsigned long long first = 0;
        for (int i = 0; i < len - 1; i++) {
            first = first * 10 + (s[i] - '0');
            if (backtrack(i + 1, first)) { ok = true; break; }
        }
        printf("%s\n", ok ? "true" : "false");
    }
    return 0;
}
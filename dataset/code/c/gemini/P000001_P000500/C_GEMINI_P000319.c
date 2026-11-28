#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isOneEditDistance(const char* s, const char* t) {
    if (strcmp(s, t) == 0) return false;
    int m = strlen(s), n = strlen(t);
    if (abs(m - n) > 1) return false;
    int min_len = m < n ? m : n;
    for (int i = 0; i < min_len; i++) {
        if (s[i] != t[i]) {
            if (m == n) return strcmp(s + i + 1, t + i + 1) == 0;
            else if (m < n) return strcmp(s + i, t + i + 1) == 0;
            else return strcmp(s + i + 1, t + i) == 0;
        }
    }
    return abs(m - n) == 1;
}

int main() {
    char s[1005], t[1005];
    if (scanf("%1004s %1004s", s, t) == 2) {
        printf("%s\n", isOneEditDistance(s, t) ? "Yes" : "No");
    }
    return 0;
}
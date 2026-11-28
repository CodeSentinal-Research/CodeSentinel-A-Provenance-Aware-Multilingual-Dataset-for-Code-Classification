#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canConstruct(const char* r, const char* m) {
    int cnt[26] = {0};
    int len_m = strlen(m), len_r = strlen(r);
    for (int i = 0; i < len_m; i++) cnt[m[i] - 'a']++;
    for (int i = 0; i < len_r; i++) {
        if (--cnt[r[i] - 'a'] < 0) return false;
    }
    return true;
}

int main() {
    char r[1005], m[1005];
    if (scanf("%1004s %1004s", r, m) == 2) {
        printf("%s\n", canConstruct(r, m) ? "Yes" : "No");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isIsomorphic(const char* s, const char* t) {
    int len_s = strlen(s), len_t = strlen(t);
    if (len_s != len_t) return false;
    char st[256] = {0};
    char ts[256] = {0};
    for (int i = 0; i < len_s; i++) {
        unsigned char c1 = s[i], c2 = t[i];
        if (st[c1] && st[c1] != c2) return false;
        if (ts[c2] && ts[c2] != c1) return false;
        st[c1] = c2;
        ts[c2] = c1;
    }
    return true;
}

int main() {
    char s[1005], t[1005];
    if (scanf("%1004s %1004s", s, t) == 2) {
        printf("%s\n", isIsomorphic(s, t) ? "Yes" : "No");
    }
    return 0;
}
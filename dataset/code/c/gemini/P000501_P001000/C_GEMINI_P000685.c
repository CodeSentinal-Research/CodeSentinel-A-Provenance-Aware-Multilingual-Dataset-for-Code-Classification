#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool is_pal_rec(const char* s, int l, int r) {
    if (l >= r) return true;
    if (s[l] != s[r]) return false;
    return is_pal_rec(s, l + 1, r - 1);
}
int main() {
    char s[100005];
    if (scanf("%100004s", s) == 1) {
        printf("%s\n", is_pal_rec(s, 0, strlen(s) - 1) ? "true" : "false");
    }
    return 0;
}
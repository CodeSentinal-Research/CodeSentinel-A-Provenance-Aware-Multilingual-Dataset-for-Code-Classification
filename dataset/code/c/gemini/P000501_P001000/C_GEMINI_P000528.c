#include <stdio.h>
#include <string.h>
#define MAX_N 100005
char s[MAX_N];
int main() {
    if (scanf("%100004s", s) == 1) {
        int l = 0, r = strlen(s) - 1;
        // Binary search loop to narrow down range
        while (l <= r && s[l] == 'L') l++;
        while (r >= l && s[r] == 'R') r--;
        int ans = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] != 'S') ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
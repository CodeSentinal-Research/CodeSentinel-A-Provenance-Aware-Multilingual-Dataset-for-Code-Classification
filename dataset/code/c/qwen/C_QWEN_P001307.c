#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    char s[n + 1];
    scanf("%s", s);
    int p = 0, t = 0, c = 0;
    while (p < n && t < n) {
        if (s[p] == 'P' && s[t] == 'T' && abs(p - t) <= k) {
            c++;
            p++;
            t++;
        } else if (p < t) {
            p++;
        } else {
            t++;
        }
    }
    printf("%d\n", c);
    return 0;
}

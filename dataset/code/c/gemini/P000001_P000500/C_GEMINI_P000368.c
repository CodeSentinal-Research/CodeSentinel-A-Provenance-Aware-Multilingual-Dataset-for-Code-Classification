#include <stdio.h>
#include <string.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        char s[1005];
        int max_idx = 0, max_len = -1;
        for (int i = 0; i < n; i++) {
            scanf("%1004s", s);
            int len = strlen(s);
            if (len > max_len) {
                max_len = len;
                max_idx = i;
            }
        }
        printf("%d\n", max_idx);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        char s[1005];
        int min_idx = 0, min_len = 1000000;
        for (int i = 0; i < n; i++) {
            scanf("%1004s", s);
            int len = strlen(s);
            if (len < min_len) {
                min_len = len;
                min_idx = i;
            }
        }
        printf("%d\n", min_idx);
    }
    return 0;
}
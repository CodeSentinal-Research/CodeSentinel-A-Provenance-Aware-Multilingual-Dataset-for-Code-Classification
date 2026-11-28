#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long cur = 0;
        int longest = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            cur += x;
            if (cur < 0) longest = i + 1;
        }
        printf("%d\n", longest);
    }
    return 0;
}
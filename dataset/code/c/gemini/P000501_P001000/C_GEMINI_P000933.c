#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val;
                scanf("%d", &val);
                int exp = (i == j) ? 1 : 0;
                if (val != exp) ok = false;
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
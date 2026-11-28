#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            if (val % 2 != 0 && idx == -1) idx = i;
        }
        printf("%d\n", idx);
    }
    return 0;
}
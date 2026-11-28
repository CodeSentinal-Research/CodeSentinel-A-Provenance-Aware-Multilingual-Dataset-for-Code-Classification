#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            if (v == 1 && idx == -1) idx = i;
        }
        printf("%d\n", idx);
    }
    return 0;
}
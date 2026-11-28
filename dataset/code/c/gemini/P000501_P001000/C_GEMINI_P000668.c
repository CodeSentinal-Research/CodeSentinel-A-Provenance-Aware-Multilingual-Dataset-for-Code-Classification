#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int size;
    if (scanf("%d", &size) == 1) {
        for (int i = 0; i < size; i++) scanf("%d", &vals[i]);
        int m, n; scanf("%d %d", &m, &n);
        int cur = 0, first = 1;
        while (cur < size) {
            for (int i = 0; i < m && cur + i < size; i++) {
                if (!first) printf(" ");
                printf("%d", vals[cur + i]);
                first = 0;
            }
            cur += m + n;
        }
        printf("\n");
    }
    return 0;
}
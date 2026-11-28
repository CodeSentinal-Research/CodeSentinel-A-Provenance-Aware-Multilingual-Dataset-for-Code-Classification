#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int k; scanf("%d", &k);
        if (k == 1) return 0;
        int first = 1;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % k != 0) {
                if (!first) printf(" ");
                printf("%d", vals[i]);
                first = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
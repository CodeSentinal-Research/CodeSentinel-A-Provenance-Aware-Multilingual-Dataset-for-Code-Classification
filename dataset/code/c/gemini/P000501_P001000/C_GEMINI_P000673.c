#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        if (n > 1) {
            printf("%d", vals[n - 1]);
            for (int i = 0; i < n - 1; i++) printf(" %d", vals[i]);
            printf("\n");
        } else if (n == 1) {
            printf("%d\n", vals[0]);
        }
    }
    return 0;
}
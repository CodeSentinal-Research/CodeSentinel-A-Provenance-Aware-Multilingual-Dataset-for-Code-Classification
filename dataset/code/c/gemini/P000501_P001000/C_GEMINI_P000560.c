#include <stdio.h>
#define MAX_N 100005
int q[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &q[i]);
        int half = n / 2;
        for (int i = 0; i < half; i++) {
            printf("%d %d%s", q[i], q[i + half], i + 1 == half ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}
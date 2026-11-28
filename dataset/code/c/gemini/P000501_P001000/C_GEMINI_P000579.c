#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        for (int i = n - 1; i >= 0; i--) printf("%d%s", vals[i], i == 0 ? "" : " ");
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int val; scanf("%d", &val);
        printf("%d", val);
        for (int i = 0; i < n; i++) printf(" %d", vals[i]);
        printf("\n");
    }
    return 0;
}
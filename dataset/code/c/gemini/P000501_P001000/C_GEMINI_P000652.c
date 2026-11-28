#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int val; scanf("%d", &val);
        int inserted = 0, first = 1;
        for (int i = 0; i < n; i++) {
            if (!inserted && val <= vals[i]) {
                if (!first) printf(" ");
                printf("%d", val);
                inserted = 1;
                first = 0;
            }
            if (!first) printf(" ");
            printf("%d", vals[i]);
            first = 0;
        }
        if (!inserted) {
            if (!first) printf(" ");
            printf("%d", val);
        }
        printf("\n");
    }
    return 0;
}
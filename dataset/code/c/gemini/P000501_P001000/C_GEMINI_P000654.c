#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int pivot = vals[n - 1];
        int first = 1;
        for (int i = 0; i < n - 1; i++) {
            if (vals[i] < pivot) {
                if (!first) printf(" ");
                printf("%d", vals[i]);
                first = 0;
            }
        }
        if (!first) printf(" ");
        printf("%d", pivot);
        for (int i = 0; i < n - 1; i++) {
            if (vals[i] >= pivot) {
                printf(" %d", vals[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
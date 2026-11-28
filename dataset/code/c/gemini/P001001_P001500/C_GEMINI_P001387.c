#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmpIntEq(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* a = (int*)malloc(n * sizeof(int));
        int* b = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);

        qsort(a, n, sizeof(int), cmpIntEq);
        qsort(b, n, sizeof(int), cmpIntEq);

        bool equal = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                equal = false;
                break;
            }
        }
        printf("%d\n", equal ? 1 : 0);
        free(a);
        free(b);
    }
    return 0;
}
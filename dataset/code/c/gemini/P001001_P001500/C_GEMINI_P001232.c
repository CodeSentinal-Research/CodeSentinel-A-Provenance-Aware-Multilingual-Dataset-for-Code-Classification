#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Activity;

int cmpAct(const void* a, const void* b) {
    return ((Activity*)a)->end - ((Activity*)b)->end;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        Activity* arr = (Activity*)malloc(n * sizeof(Activity));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i].start);
        for (int i = 0; i < n; i++) scanf("%d", &arr[i].end);

        qsort(arr, n, sizeof(Activity), cmpAct);
        int count = 0, lastEnd = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i].start >= lastEnd) {
                count++;
                lastEnd = arr[i].end;
            }
        }
        printf("%d\n", count);
        free(arr);
    }
    return 0;
}
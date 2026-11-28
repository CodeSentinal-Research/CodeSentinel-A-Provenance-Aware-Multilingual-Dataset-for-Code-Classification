#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int* dep = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &dep[i]);

        qsort(arr, n, sizeof(int), cmpInt);
        qsort(dep, n, sizeof(int), cmpInt);

        int i = 0, j = 0;
        int platNeeded = 0, maxPlat = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platNeeded++;
                maxPlat = MAX(maxPlat, platNeeded);
                i++;
            } else {
                platNeeded--;
                j++;
            }
        }
        printf("%d\n", maxPlat);
        free(arr);
        free(dep);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (arr[mid] == 0) {
                int t = arr[low]; arr[low] = arr[mid]; arr[mid] = t;
                low++; mid++;
            } else if (arr[mid] == 1) {
                mid++;
            } else {
                int t = arr[mid]; arr[mid] = arr[high]; arr[high] = t;
                high--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
        free(arr);
    }
    return 0;
}
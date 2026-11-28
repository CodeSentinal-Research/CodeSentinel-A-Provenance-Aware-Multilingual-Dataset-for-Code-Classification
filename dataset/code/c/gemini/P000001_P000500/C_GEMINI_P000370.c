#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* arr = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int dup = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] == arr[j]) {
                    dup = arr[i];
                    break;
                }
            }
            if (dup != -1) break;
        }
        printf("%d\n", dup);
        free(arr);
    }
    return 0;
}
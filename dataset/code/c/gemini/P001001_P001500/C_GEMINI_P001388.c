#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        for (int i = 0; i <= n - k; i++) {
            int distinct = 0;
            for (int j = i; j < i + k; j++) {
                int seen = 0;
                for (int l = i; l < j; l++) {
                    if (arr[l] == arr[j]) { seen = 1; break; }
                }
                if (!seen) distinct++;
            }
            printf("%d%s", distinct, i == n - k ? "" : " ");
        }
        printf("\n");
        free(arr);
    }
    return 0;
}
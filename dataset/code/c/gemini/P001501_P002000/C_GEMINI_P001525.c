#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        int* firstSeen = (int*)malloc((2 * n + 1) * sizeof(int));
        for (int i = 0; i <= 2 * n; i++) firstSeen[i] = -2;
        firstSeen[n] = -1;

        int diff = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            diff += (arr[i] % 2 == 0) ? 1 : -1;
            if (firstSeen[diff + n] != -2) {
                maxLen = MAX(maxLen, i - firstSeen[diff + n]);
            } else {
                firstSeen[diff + n] = i;
            }
        }
        printf("%d\n", maxLen);
        free(arr);
        free(firstSeen);
    }
    return 0;
}
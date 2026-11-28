#include <stdio.h>

int main() {
    int n, val;
    if (scanf("%d %d", &n, &val) == 2) {
        int arr[n + 1];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        arr[n] = val;
        int i = n;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (arr[i] < arr[p]) {
                int t = arr[i]; arr[i] = arr[p]; arr[p] = t;
                i = p;
            } else {
                break;
            }
        }
        for (int j = 0; j <= n; j++) {
            printf("%d%s", arr[j], (j == n ? "" : " "));
        }
        printf("\n");
    }
    return 0;
}
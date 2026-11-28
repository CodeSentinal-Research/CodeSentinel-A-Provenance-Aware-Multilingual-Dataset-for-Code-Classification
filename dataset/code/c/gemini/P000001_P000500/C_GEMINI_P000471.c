#include <stdio.h>
#define MAX_N 10005
int arr[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = i + 1; j < n; j++) if (arr[j] < arr[i]) c++;
            printf("%d%s", c, i == n - 1 ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int level = 0, start = 0;
        while (start < n) {
            int count = 1 << level;
            int end = (start + count < n) ? start + count : n;
            for (int i = start; i < end; i++) {
                printf("%d%s", arr[i], (i == end - 1 ? "" : " "));
            }
            printf("\n");
            start = end;
            level++;
        }
    }
    return 0;
}
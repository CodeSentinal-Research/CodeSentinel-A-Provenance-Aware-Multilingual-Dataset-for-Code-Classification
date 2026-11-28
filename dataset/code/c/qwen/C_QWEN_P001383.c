#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        int idx = abs(a[i]) - 1;
        if (a[idx] > 0) a[idx] = -a[idx];
    }
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (!first) printf(" ");
            printf("%d", i + 1);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int first = 1;
    for (int i = 0; i < n; i++) {
        int idx = abs(a[i]) - 1;
        if (a[idx] < 0) {
            if (!first) printf(" ");
            printf("%d", idx + 1);
            first = 0;
        } else {
            a[idx] = -a[idx];
        }
    }
    printf("\n");
    return 0;
}

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int count[100001] = {0};
    for (int i = 0; i < n; i++) count[a[i]]++;
    int total = 0;
    for (int i = 0; i <= 100000; i++) {
        if (count[i]) {
            int groups = (count[i] + i) / (i + 1);
            total += groups * (i + 1);
        }
    }
    printf("%d\n", total);
    return 0;
}

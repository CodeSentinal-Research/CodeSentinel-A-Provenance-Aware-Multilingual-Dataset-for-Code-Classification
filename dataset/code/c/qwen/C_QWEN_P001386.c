#include <stdio.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int count[100001] = {0}, dist = 0;
    for (int i = 0; i < k; i++) {
        if (!count[a[i]]++) dist++;
    }
    printf("%d ", dist);
    for (int i = k; i < n; i++) {
        if (!--count[a[i - k]]) dist--;
        if (!count[a[i]]++) dist++;
        printf("%d ", dist);
    }
    printf("\n");
    return 0;
}

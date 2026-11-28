#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n], b[m];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    
    int res[n + m];
    int i = 0, j = 0, idx = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) res[idx++] = a[i++];
        else res[idx++] = b[j++];
    }
    while (i < n) res[idx++] = a[i++];
    while (j < m) res[idx++] = b[j++];
    
    for (int i = 0; i < idx; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}

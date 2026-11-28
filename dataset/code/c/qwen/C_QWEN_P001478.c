#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][2], b[m][2];
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    for (int i = 0; i < m; i++) scanf("%d %d", &b[i][0], &b[i][1]);
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        int start = a[i][0] > b[j][0] ? a[i][0] : b[j][0];
        int end = a[i][1] < b[j][1] ? a[i][1] : b[j][1];
        if (start <= end) printf("%d %d\n", start, end);
        if (a[i][1] < b[j][1]) i++;
        else j++;
    }
    return 0;
}

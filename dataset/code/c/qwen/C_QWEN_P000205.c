#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n], b[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    int i=0, j=0, count=0;
    double med = 0;
    while(count <= n) {
        med = (i<n && (j>=n || a[i]<b[j])) ? a[i++] : b[j++];
        count++;
    }
    printf("%.2f\n", med);
    return 0;
}

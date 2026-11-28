#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int min_p = a[0], max_p = 0;
    for(int i=1; i<n; i++) {
        if(a[i] - min_p > max_p) max_p = a[i] - min_p;
        if(a[i] < min_p) min_p = a[i];
    }
    printf("%d\n", max_p);
    return 0;
}

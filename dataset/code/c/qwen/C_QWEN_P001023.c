#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int i; scanf("%d", &i);
    if(i == 0) printf("-1\n");
    else printf("%d\n", a[(i-1)/2]);
    return 0;
}

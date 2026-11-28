#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int i; scanf("%d", &i);
    int level = 0;
    while(i > 0) { i = (i-1)/2; level++; }
    printf("%d\n", level);
    return 0;
}

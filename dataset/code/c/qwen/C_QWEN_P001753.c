#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int val[n]; for(int i=0; i<n; i++) scanf("%d", &val[i]);
    printf("%d\n", val[n-1]);
    return 0;
}

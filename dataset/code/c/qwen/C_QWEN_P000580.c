#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    printf("%d\n", vals[n/2]);
    return 0;
}

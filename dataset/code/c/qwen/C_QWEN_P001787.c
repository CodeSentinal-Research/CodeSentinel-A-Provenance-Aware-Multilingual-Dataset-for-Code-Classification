#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int val[n]; for(int i=0; i<n; i++) scanf("%d", &val[i]);
    int key; scanf("%d", &key);
    for(int i=0; i<n; i++) printf("%d ", val[i]);
    printf("\n");
    return 0;
}

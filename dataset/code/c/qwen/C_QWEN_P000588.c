#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int vals[n], random[n];
    for(int i=0; i<n; i++) scanf("%d %d", &vals[i], &random[i]);
    for(int i=0; i<n; i++) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}

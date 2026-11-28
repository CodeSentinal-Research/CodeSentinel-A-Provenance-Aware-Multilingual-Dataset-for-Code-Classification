#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int edges = 0;
    for(int i=0; i<n; i++) {
        int k; scanf("%d", &k);
        edges += k;
    }
    printf("%d\n", edges / 2);
    return 0;
}

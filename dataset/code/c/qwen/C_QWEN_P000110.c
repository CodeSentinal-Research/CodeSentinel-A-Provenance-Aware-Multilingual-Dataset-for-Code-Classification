#include <stdio.h>
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int count = 0;
    for(int i=0; i<n; i++) { int x; scanf("%d", &x); if(x == target) count++; }
    printf("%d\n", count);
    return 0;
}

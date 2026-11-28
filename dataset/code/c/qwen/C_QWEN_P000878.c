#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int count = 0;
    for(int i=0; i<n; i++) { int curr = 0; for(int j=i; j<n; j++) { curr |= a[j]; count++; } }
    printf("%d\n", count);
    return 0;
}

#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int max_xor = 0;
    for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) { int x = a[i] ^ a[j]; if(x > max_xor) max_xor = x; }
    printf("%d\n", max_xor);
    return 0;
}

#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int total = 0;
    for(int i=0; i<32; i++) {
        int count = 0;
        for(int j=0; j<n; j++) if(a[j] & (1 << i)) count++;
        total += count * (n - count);
    }
    printf("%d\n", total);
    return 0;
}

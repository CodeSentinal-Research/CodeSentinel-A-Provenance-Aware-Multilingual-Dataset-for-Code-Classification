#include <stdio.h>
int solve(int *a, int n, int k, int target, int *mask) {
    if(target == 0) return 1;
    for(int i=0; i<n; i++) {
        if(!((*mask) & (1<<i)) && a[i] <= target) {
            (*mask) |= (1<<i);
            if(solve(a, n, k, target-a[i], mask)) return 1;
            (*mask) &= ~(1<<i);
        }
    }
    return 0;
}
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; int sum = 0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); sum += a[i]; }
    if(sum % k != 0) { printf("NO\n"); return 0; }
    int target = sum / k;
    int mask = 0;
    printf("%s\n", solve(a, n, k, target, &mask) ? "YES" : "NO");
    return 0;
}

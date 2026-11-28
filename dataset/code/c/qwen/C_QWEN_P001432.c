#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int count[11][11] = {0};
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) { int t = a; a = b; b = t; }
        total += count[a][b];
        count[a][b]++;
    }
    printf("%lld\n", total);
    return 0;
}

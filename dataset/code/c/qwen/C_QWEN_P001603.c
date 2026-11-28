#include <stdio.h>

int main() {
    int n; long long x; scanf("%d %lld", &n, &x);
    long long sum = 0;
    for(int i=0; i<n; i++) {
        int val; scanf("%d", &val);
        sum += val;
        if(sum >= x) { printf("%d\n", i + 1); return 0; }
    }
    printf("-1\n");
    return 0;
}

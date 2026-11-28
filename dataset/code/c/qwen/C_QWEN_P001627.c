#include <stdio.h>

int main() {
    int n, k; scanf("%d %d", &n, &k);
    long long sum = 0;
    int count = 0;
    for(int i=0; i<n; i++) {
        int val; scanf("%d", &val);
        sum += val;
        if(sum % k == 0) count++;
    }
    printf("%d\n", count);
    return 0;
}

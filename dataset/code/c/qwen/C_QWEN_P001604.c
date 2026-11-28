#include <stdio.h>
#include <string.h>

#define HASH_SIZE 200003
long long hk[HASH_SIZE], hv[HASH_SIZE];

void put(long long k, long long v) {
    int i = (k % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
    while(hk[i] && hk[i] != k) i = (i + 1) % HASH_SIZE;
    hk[i] = k; hv[i] += v;
}
long long get(long long k) {
    int i = (k % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
    while(hk[i] && hk[i] != k) i = (i + 1) % HASH_SIZE;
    return hk[i] == k ? hv[i] : 0;
}

int main() {
    int n; long long k; scanf("%d %lld", &n, &k);
    long long sum = 0, count = 0;
    put(0, 1);
    for(int i=0; i<n; i++) {
        int val; scanf("%d", &val);
        sum += val;
        count += get(sum - k);
        put(sum, 1);
    }
    printf("%lld\n", count);
    return 0;
}

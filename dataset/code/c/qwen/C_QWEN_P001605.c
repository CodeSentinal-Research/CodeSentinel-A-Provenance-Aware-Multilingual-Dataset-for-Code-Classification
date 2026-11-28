#include <stdio.h>
#include <string.h>

#define HASH_SIZE 200003
long long hk[HASH_SIZE], hv[HASH_SIZE];

void put(long long k, long long v) {
    int i = (k % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
    while(hk[i] && hk[i] != k) i = (i + 1) % HASH_SIZE;
    hk[i] = k; hv[i] = v;
}
long long get(long long k) {
    int i = (k % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
    while(hk[i] && hk[i] != k) i = (i + 1) % HASH_SIZE;
    return hk[i] == k ? hv[i] : -1;
}

int main() {
    int n; long long k; scanf("%d %lld", &n, &k);
    long long sum = 0;
    int max_len = 0;
    put(0, 0);
    for(int i=0; i<n; i++) {
        int val; scanf("%d", &val);
        sum += val;
        long long prev = get(sum - k);
        if(prev != -1) {
            if(i + 1 - prev > max_len) max_len = i + 1 - prev;
        }
        if(get(sum) == -1) put(sum, i + 1);
    }
    printf("%d\n", max_len);
    return 0;
}

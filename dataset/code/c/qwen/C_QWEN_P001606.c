#include <stdio.h>
#include <string.h>

#define HASH_SIZE 200003
int hk[HASH_SIZE], hv[HASH_SIZE];

void put(int k, int v) {
    int i = (k % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
    while(hk[i] && hk[i] != k) i = (i + 1) % HASH_SIZE;
    hk[i] = k; hv[i] += v;
}
int get(int k) {
    int i = (k % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
    while(hk[i] && hk[i] != k) i = (i + 1) % HASH_SIZE;
    return hk[i] == k ? hv[i] : 0;
}

int main() {
    int n; scanf("%d", &n);
    int sum = 0, count = 0;
    put(0, 1);
    for(int i=0; i<n; i++) {
        int val; scanf("%d", &val);
        sum += (val == 0 ? -1 : 1);
        count += get(sum);
        put(sum, 1);
    }
    printf("%d\n", count);
    return 0;
}

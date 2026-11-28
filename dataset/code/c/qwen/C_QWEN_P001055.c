#include <stdio.h>
#include <stdlib.h>
int main() {
    int target, fuel; scanf("%d%d", &target, &fuel);
    int n; scanf("%d", &n);
    int pos[n], f[n];
    for(int i=0; i<n; i++) scanf("%d%d", &pos[i], &f[i]);
    int stops = 0;
    int cur = fuel;
    for(int i=0; i<n; i++) {
        int dist = pos[i] - (i==0 ? 0 : pos[i-1]);
        cur -= dist;
        if(cur < 0) {
            // find max fuel from previous stations
            int max_f = -1, max_idx = -1;
            for(int j=0; j<i; j++) {
                if(f[j] > max_f) { max_f = f[j]; max_idx = j; }
            }
            if(max_idx == -1) { printf("-1\n"); return 0; }
            cur += max_f;
            f[max_idx] = 0;
            stops++;
            i--; // recheck
        }
    }
    int dist = target - (n==0 ? 0 : pos[n-1]);
    cur -= dist;
    if(cur < 0) {
        int max_f = -1, max_idx = -1;
        for(int j=0; j<n; j++) {
            if(f[j] > max_f) { max_f = f[j]; max_idx = j; }
        }
        if(max_idx == -1) { printf("-1\n"); return 0; }
        cur += max_f;
        stops++;
    }
    printf("%d\n", stops);
    return 0;
}

#include <stdio.h>
#include <string.h>
#define MAX_CAP 10005
int keys[MAX_CAP], vals[MAX_CAP], freqs[MAX_CAP], times[MAX_CAP];
int size = 0, timer = 0;
int main() {
    int cap, q;
    if (scanf("%d %d", &cap, &q) == 2) {
        while (q--) {
            timer++;
            char cmd[16]; scanf("%15s", cmd);
            if (strcmp(cmd, "put") == 0) {
                int k, v; scanf("%d %d", &k, &v);
                if (cap == 0) continue;
                int found = -1;
                for (int i = 0; i < size; i++) if (keys[i] == k) { found = i; break; }
                if (found != -1) {
                    vals[found] = v; freqs[found]++; times[found] = timer;
                } else {
                    if (size >= cap) {
                        int evict = 0;
                        for (int i = 1; i < size; i++) {
                            if (freqs[i] < freqs[evict] || (freqs[i] == freqs[evict] && times[i] < times[evict])) {
                                evict = i;
                            }
                        }
                        for (int i = evict; i < size - 1; i++) {
                            keys[i] = keys[i+1]; vals[i] = vals[i+1]; freqs[i] = freqs[i+1]; times[i] = times[i+1];
                        }
                        size--;
                    }
                    keys[size] = k; vals[size] = v; freqs[size] = 1; times[size] = timer;
                    size++;
                }
            } else if (strcmp(cmd, "get") == 0) {
                int k; scanf("%d", &k);
                int found = -1;
                for (int i = 0; i < size; i++) if (keys[i] == k) { found = i; break; }
                if (found != -1) {
                    freqs[found]++; times[found] = timer;
                    printf("%d\n", vals[found]);
                } else {
                    printf("-1\n");
                }
            }
        }
    }
    return 0;
}
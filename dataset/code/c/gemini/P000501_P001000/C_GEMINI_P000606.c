#include <stdio.h>
#include <string.h>
#define MAX_CAP 10005
int keys[MAX_CAP], vals[MAX_CAP];
int size = 0;
int main() {
    int cap, q;
    if (scanf("%d %d", &cap, &q) == 2) {
        while (q--) {
            char cmd[16]; scanf("%15s", cmd);
            if (strcmp(cmd, "put") == 0) {
                int k, v; scanf("%d %d", &k, &v);
                int found = -1;
                for (int i = 0; i < size; i++) if (keys[i] == k) { found = i; break; }
                if (found != -1) {
                    for (int i = found; i > 0; i--) { keys[i] = keys[i-1]; vals[i] = vals[i-1]; }
                } else {
                    if (size < cap) size++;
                    for (int i = size - 1; i > 0; i--) { keys[i] = keys[i-1]; vals[i] = vals[i-1]; }
                }
                keys[0] = k; vals[0] = v;
            } else if (strcmp(cmd, "get") == 0) {
                int k; scanf("%d", &k);
                int found = -1;
                for (int i = 0; i < size; i++) if (keys[i] == k) { found = i; break; }
                if (found != -1) {
                    int v = vals[found];
                    for (int i = found; i > 0; i--) { keys[i] = keys[i-1]; vals[i] = vals[i-1]; }
                    keys[0] = k; vals[0] = v;
                    printf("%d\n", v);
                } else {
                    printf("-1\n");
                }
            }
        }
    }
    return 0;
}
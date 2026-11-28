#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 5005
char keys[MAX_ITEMS][64];
int counts[MAX_ITEMS];
int size = 0;
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[32]; scanf("%31s", cmd);
            if (strcmp(cmd, "inc") == 0) {
                char k[64]; scanf("%63s", k);
                int found = -1;
                for (int i = 0; i < size; i++) if (strcmp(keys[i], k) == 0) { found = i; break; }
                if (found != -1) counts[found]++;
                else { strcpy(keys[size], k); counts[size++] = 1; }
            } else if (strcmp(cmd, "dec") == 0) {
                char k[64]; scanf("%63s", k);
                int found = -1;
                for (int i = 0; i < size; i++) if (strcmp(keys[i], k) == 0) { found = i; break; }
                if (found != -1) {
                    counts[found]--;
                    if (counts[found] == 0) {
                        for (int i = found; i < size - 1; i++) {
                            strcpy(keys[i], keys[i+1]); counts[i] = counts[i+1];
                        }
                        size--;
                    }
                }
            } else if (strcmp(cmd, "getMaxKey") == 0) {
                if (size == 0) printf("\n");
                else {
                    int max_v = -1, max_idx = -1;
                    for (int i = 0; i < size; i++) if (counts[i] > max_v) { max_v = counts[i]; max_idx = i; }
                    printf("%s\n", keys[max_idx]);
                }
            } else if (strcmp(cmd, "getMinKey") == 0) {
                if (size == 0) printf("\n");
                else {
                    int min_v = 1e9, min_idx = -1;
                    for (int i = 0; i < size; i++) if (counts[i] < min_v) { min_v = counts[i]; min_idx = i; }
                    printf("%s\n", keys[min_idx]);
                }
            }
        }
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#define MAX_WINS 105
#define MAX_HIST 105
char hist[MAX_WINS][MAX_HIST][128];
int cur_idx[MAX_WINS], hist_sz[MAX_WINS];
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[32]; scanf("%31s", cmd);
            if (strcmp(cmd, "newWindow") == 0) {
                int id; char home[128]; scanf("%d %127s", &id, home);
                strcpy(hist[id][0], home);
                cur_idx[id] = 0; hist_sz[id] = 1;
            } else if (strcmp(cmd, "visit") == 0) {
                int id; char url[128]; scanf("%d %127s", &id, url);
                cur_idx[id]++;
                strcpy(hist[id][cur_idx[id]], url);
                hist_sz[id] = cur_idx[id] + 1;
            } else if (strcmp(cmd, "back") == 0) {
                int id, steps; scanf("%d %d", &id, &steps);
                cur_idx[id] = (cur_idx[id] - steps > 0) ? cur_idx[id] - steps : 0;
                printf("%s\n", hist[id][cur_idx[id]]);
            } else if (strcmp(cmd, "forward") == 0) {
                int id, steps; scanf("%d %d", &id, &steps);
                cur_idx[id] = (cur_idx[id] + steps < hist_sz[id] - 1) ? cur_idx[id] + steps : hist_sz[id] - 1;
                printf("%s\n", hist[id][cur_idx[id]]);
            } else if (strcmp(cmd, "currentPage") == 0) {
                int id; scanf("%d", &id);
                printf("%s\n", hist[id][cur_idx[id]]);
            } else if (strcmp(cmd, "closeWindow") == 0) {
                int id; scanf("%d", &id);
                hist_sz[id] = 0;
            }
        }
    }
    return 0;
}
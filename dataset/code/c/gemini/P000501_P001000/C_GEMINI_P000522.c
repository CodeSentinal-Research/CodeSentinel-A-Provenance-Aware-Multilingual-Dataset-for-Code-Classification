#include <stdio.h>
#include <string.h>
#define MAX_N 5005
char history[MAX_N][128];
int main() {
    char home[128];
    int q;
    if (scanf("%127s %d", home, &q) == 2) {
        strcpy(history[0], home);
        int curr = 0, size = 1;
        while (q--) {
            char cmd[16];
            scanf("%15s", cmd);
            if (strcmp(cmd, "visit") == 0) {
                char url[128];
                scanf("%127s", url);
                curr++;
                strcpy(history[curr], url);
                size = curr + 1;
            } else if (strcmp(cmd, "back") == 0) {
                int steps; scanf("%d", &steps);
                curr = (curr - steps < 0) ? 0 : curr - steps;
                printf("%s\n", history[curr]);
            } else if (strcmp(cmd, "forward") == 0) {
                int steps; scanf("%d", &steps);
                curr = (curr + steps >= size) ? size - 1 : curr + steps;
                printf("%s\n", history[curr]);
            }
        }
    }
    return 0;
}
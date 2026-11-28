#include <stdio.h>
#include <string.h>
#define MAX_HIST 1005
#define MAX_LEN 10005
char history[MAX_HIST][MAX_LEN];
int cur = 0, total = 1;
int main() {
    int q;
    history[0][0] = '\0';
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[32]; scanf("%31s", cmd);
            if (strcmp(cmd, "type") == 0) {
                char s[1005]; scanf("%1004s", s);
                cur++;
                strcpy(history[cur], history[cur-1]);
                strcat(history[cur], s);
                total = cur + 1;
            } else if (strcmp(cmd, "undo") == 0) {
                if (cur > 0) cur--;
            } else if (strcmp(cmd, "redo") == 0) {
                if (cur + 1 < total) cur++;
            } else if (strcmp(cmd, "print") == 0) {
                printf("%s\n", history[cur]);
            }
        }
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#define MAX_TABS 1005
char tabs[MAX_TABS][128];
int size = 0, cur_idx = 0;
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[32]; scanf("%31s", cmd);
            if (strcmp(cmd, "open") == 0) {
                scanf("%127s", tabs[size]);
                cur_idx = size++;
            } else if (strcmp(cmd, "close") == 0) {
                int i; scanf("%d", &i);
                for (int j = i; j < size - 1; j++) strcpy(tabs[j], tabs[j+1]);
                size--;
                if (cur_idx >= size) cur_idx = (size > 0) ? size - 1 : 0;
            } else if (strcmp(cmd, "switch") == 0) {
                scanf("%d", &cur_idx);
            } else if (strcmp(cmd, "moveLeft") == 0) {
                int i; scanf("%d", &i);
                if (i > 0) {
                    char tmp[128]; strcpy(tmp, tabs[i]); strcpy(tabs[i], tabs[i-1]); strcpy(tabs[i-1], tmp);
                    if (cur_idx == i) cur_idx = i - 1;
                    else if (cur_idx == i - 1) cur_idx = i;
                }
            } else if (strcmp(cmd, "moveRight") == 0) {
                int i; scanf("%d", &i);
                if (i < size - 1) {
                    char tmp[128]; strcpy(tmp, tabs[i]); strcpy(tabs[i], tabs[i+1]); strcpy(tabs[i+1], tmp);
                    if (cur_idx == i) cur_idx = i + 1;
                    else if (cur_idx == i + 1) cur_idx = i;
                }
            } else if (strcmp(cmd, "current") == 0) {
                printf("%s\n", size > 0 ? tabs[cur_idx] : "");
            }
        }
    }
    return 0;
}
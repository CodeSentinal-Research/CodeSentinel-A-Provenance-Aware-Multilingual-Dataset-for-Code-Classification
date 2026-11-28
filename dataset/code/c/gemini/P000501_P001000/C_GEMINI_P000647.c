#include <stdio.h>
#include <string.h>
#define MAX_SONGS 1005
char playlist[MAX_SONGS][128];
int size = 0, cur = 0;
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[32]; scanf("%31s", cmd);
            if (strcmp(cmd, "addSong") == 0) {
                scanf("%127s", playlist[size++]);
            } else if (strcmp(cmd, "removeSong") == 0) {
                char title[128]; scanf("%127s", title);
                int found = -1;
                for (int i = 0; i < size; i++) if (strcmp(playlist[i], title) == 0) { found = i; break; }
                if (found != -1) {
                    for (int i = found; i < size - 1; i++) strcpy(playlist[i], playlist[i+1]);
                    size--;
                    if (cur >= size) cur = (size > 0) ? size - 1 : 0;
                }
            } else if (strcmp(cmd, "playNext") == 0) {
                if (size > 0) {
                    cur = (cur + 1) % size;
                    printf("%s\n", playlist[cur]);
                }
            } else if (strcmp(cmd, "playPrevious") == 0) {
                if (size > 0) {
                    cur = (cur - 1 + size) % size;
                    printf("%s\n", playlist[cur]);
                }
            } else if (strcmp(cmd, "moveSong") == 0) {
                char title[128]; int pos; scanf("%127s %d", title, &pos);
                int found = -1;
                for (int i = 0; i < size; i++) if (strcmp(playlist[i], title) == 0) { found = i; break; }
                if (found != -1) {
                    for (int i = found; i < size - 1; i++) strcpy(playlist[i], playlist[i+1]);
                    for (int i = size - 1; i > pos; i--) strcpy(playlist[i], playlist[i-1]);
                    strcpy(playlist[pos], title);
                }
            } else if (strcmp(cmd, "currentSong") == 0) {
                printf("%s\n", size > 0 ? playlist[cur] : "");
            }
        }
    }
    return 0;
}
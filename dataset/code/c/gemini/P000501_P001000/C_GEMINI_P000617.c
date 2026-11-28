#include <stdio.h>
#include <string.h>
#define MAX_N 10005
int vals[MAX_N];
int size = 0;
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[16]; scanf("%15s", cmd);
            if (strcmp(cmd, "add") == 0) {
                int x; scanf("%d", &x);
                vals[size++] = x;
            } else if (strcmp(cmd, "search") == 0) {
                int x; scanf("%d", &x);
                int found = 0;
                for (int i = 0; i < size; i++) if (vals[i] == x) { found = 1; break; }
                printf("%s\n", found ? "true" : "false");
            } else if (strcmp(cmd, "erase") == 0) {
                int x; scanf("%d", &x);
                int found = -1;
                for (int i = 0; i < size; i++) if (vals[i] == x) { found = i; break; }
                if (found != -1) {
                    vals[found] = vals[--size];
                    printf("true\n");
                } else {
                    printf("false\n");
                }
            }
        }
    }
    return 0;
}
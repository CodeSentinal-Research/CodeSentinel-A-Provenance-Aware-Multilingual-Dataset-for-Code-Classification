#include <stdio.h>
#include <string.h>
#define MAX_N 10005
int queue[MAX_N];
int main() {
    int cap, q;
    if (scanf("%d %d", &cap, &q) == 2) {
        int head = 0, tail = 0;
        while (q--) {
            char cmd[16];
            scanf("%15s", cmd);
            if (strcmp(cmd, "enqueue") == 0) {
                int x; scanf("%d", &x);
                queue[tail++] = x;
            } else if (strcmp(cmd, "dequeue") == 0) {
                if (head < tail) printf("%d\n", queue[head++]);
            } else if (strcmp(cmd, "front") == 0) {
                if (head < tail) printf("%d\n", queue[head]);
            } else if (strcmp(cmd, "isEmpty") == 0) {
                printf("%s\n", head == tail ? "true" : "false");
            }
        }
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#define MAX_N 10005
int st[MAX_N];
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        int top = -1;
        while (q--) {
            char cmd[16];
            scanf("%15s", cmd);
            if (strcmp(cmd, "push") == 0) {
                int x; scanf("%d", &x);
                st[++top] = x;
            } else if (strcmp(cmd, "pop") == 0) {
                if (top >= 0) printf("%d\n", st[top--]);
            } else if (strcmp(cmd, "top") == 0) {
                if (top >= 0) printf("%d\n", st[top]);
            } else if (strcmp(cmd, "empty") == 0) {
                printf("%s\n", top == -1 ? "true" : "false");
            }
        }
    }
    return 0;
}
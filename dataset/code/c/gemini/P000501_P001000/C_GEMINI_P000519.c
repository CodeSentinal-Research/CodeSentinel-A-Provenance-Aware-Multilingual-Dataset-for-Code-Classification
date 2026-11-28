#include <stdio.h>
#include <string.h>
#define MAX_N 10005
int s1[MAX_N], s2[MAX_N];
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        int top1 = -1, top2 = -1;
        while (q--) {
            char cmd[16];
            scanf("%15s", cmd);
            if (strcmp(cmd, "push") == 0) {
                int x; scanf("%d", &x);
                s1[++top1] = x;
            } else if (strcmp(cmd, "pop") == 0) {
                if (top2 == -1) while (top1 >= 0) s2[++top2] = s1[top1--];
                if (top2 >= 0) printf("%d\n", s2[top2--]);
            } else if (strcmp(cmd, "peek") == 0) {
                if (top2 == -1) while (top1 >= 0) s2[++top2] = s1[top1--];
                if (top2 >= 0) printf("%d\n", s2[top2]);
            } else if (strcmp(cmd, "empty") == 0) {
                printf("%s\n", top1 == -1 && top2 == -1 ? "true" : "false");
            }
        }
    }
    return 0;
}
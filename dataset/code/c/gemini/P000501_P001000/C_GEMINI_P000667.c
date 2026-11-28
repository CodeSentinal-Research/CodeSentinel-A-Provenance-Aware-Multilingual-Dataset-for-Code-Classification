#include <stdio.h>
#include <string.h>
#define MAX_Q 10005
int dq[2 * MAX_Q];
int head = MAX_Q, tail = MAX_Q;
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[32]; scanf("%31s", cmd);
            if (strcmp(cmd, "insertFront") == 0) {
                int v; scanf("%d", &v);
                dq[--head] = v;
            } else if (strcmp(cmd, "insertLast") == 0) {
                int v; scanf("%d", &v);
                dq[tail++] = v;
            } else if (strcmp(cmd, "deleteFront") == 0) {
                if (head < tail) head++;
            } else if (strcmp(cmd, "deleteLast") == 0) {
                if (head < tail) tail--;
            } else if (strcmp(cmd, "getFront") == 0) {
                printf("%d\n", (head < tail) ? dq[head] : -1);
            } else if (strcmp(cmd, "getRear") == 0) {
                printf("%d\n", (head < tail) ? dq[tail - 1] : -1);
            } else if (strcmp(cmd, "isEmpty") == 0) {
                printf("%s\n", (head == tail) ? "true" : "false");
            } else if (strcmp(cmd, "size") == 0) {
                printf("%d\n", tail - head);
            }
        }
    }
    return 0;
}
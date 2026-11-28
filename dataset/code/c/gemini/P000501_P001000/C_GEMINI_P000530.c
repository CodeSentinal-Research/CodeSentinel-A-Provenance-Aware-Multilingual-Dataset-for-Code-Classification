#include <stdio.h>
#include <string.h>
#define MAX_N 10005
int q_arr[MAX_N];
int main() {
    int cap, q;
    if (scanf("%d %d", &cap, &q) == 2) {
        int head = 0, tail = 0, count = 0;
        while (q--) {
            char cmd[16];
            scanf("%15s", cmd);
            if (strcmp(cmd, "enQueue") == 0) {
                int x; scanf("%d", &x);
                if (count < cap) {
                    q_arr[tail] = x;
                    tail = (tail + 1) % cap;
                    count++;
                    printf("true\n");
                } else {
                    printf("false\n");
                }
            } else if (strcmp(cmd, "deQueue") == 0) {
                if (count > 0) {
                    head = (head + 1) % cap;
                    count--;
                    printf("true\n");
                } else {
                    printf("false\n");
                }
            } else if (strcmp(cmd, "Front") == 0) {
                printf("%d\n", count > 0 ? q_arr[head] : -1);
            } else if (strcmp(cmd, "Rear") == 0) {
                printf("%d\n", count > 0 ? q_arr[(tail - 1 + cap) % cap] : -1);
            } else if (strcmp(cmd, "isEmpty") == 0) {
                printf("%s\n", count == 0 ? "true" : "false");
            } else if (strcmp(cmd, "isFull") == 0) {
                printf("%s\n", count == cap ? "true" : "false");
            }
        }
    }
    return 0;
}
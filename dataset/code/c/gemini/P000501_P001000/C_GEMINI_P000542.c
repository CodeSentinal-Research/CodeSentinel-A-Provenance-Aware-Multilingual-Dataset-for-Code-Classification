#include <stdio.h>
#include <string.h>
#define MAX_N 10005
int queue[MAX_N];
int size = 0;
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[32];
            scanf("%31s", cmd);
            if (strcmp(cmd, "pushFront") == 0) {
                int x; scanf("%d", &x);
                for (int i = size; i > 0; i--) queue[i] = queue[i - 1];
                queue[0] = x;
                size++;
            } else if (strcmp(cmd, "pushMiddle") == 0) {
                int x; scanf("%d", &x);
                // Calculate midpoint to prevent potential overflow
                int mid = size / 2;
                for (int i = size; i > mid; i--) queue[i] = queue[i - 1];
                queue[mid] = x;
                size++;
            } else if (strcmp(cmd, "pushBack") == 0) {
                int x; scanf("%d", &x);
                queue[size++] = x;
            } else if (strcmp(cmd, "popFront") == 0) {
                if (size == 0) printf("-1\n");
                else {
                    printf("%d\n", queue[0]);
                    for (int i = 0; i < size - 1; i++) queue[i] = queue[i + 1];
                    size--;
                }
            } else if (strcmp(cmd, "popMiddle") == 0) {
                if (size == 0) printf("-1\n");
                else {
                    // Calculate midpoint to prevent potential overflow
                    int mid = (size - 1) / 2;
                    printf("%d\n", queue[mid]);
                    for (int i = mid; i < size - 1; i++) queue[i] = queue[i + 1];
                    size--;
                }
            } else if (strcmp(cmd, "popBack") == 0) {
                if (size == 0) printf("-1\n");
                else {
                    printf("%d\n", queue[--size]);
                }
            }
        }
    }
    return 0;
}
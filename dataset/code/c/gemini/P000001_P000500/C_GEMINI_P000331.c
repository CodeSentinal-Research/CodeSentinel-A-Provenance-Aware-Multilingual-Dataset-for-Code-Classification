#include <stdio.h>
#include <string.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int res[105] = {0};
        int stack[1005], top = -1;
        int prev_time = 0;
        char log[64];
        while (scanf("%63s", log) == 1) {
            int fn_id, timestamp;
            char action[16];
            sscanf(log, "%d:%15[^:]:%d", &fn_id, action, &timestamp);
            if (strcmp(action, "start") == 0) {
                if (top >= 0) {
                    res[stack[top]] += timestamp - prev_time;
                }
                stack[++top] = fn_id;
                prev_time = timestamp;
            } else {
                res[stack[top--]] += timestamp - prev_time + 1;
                prev_time = timestamp + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%d%s", res[i], i == n - 1 ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}
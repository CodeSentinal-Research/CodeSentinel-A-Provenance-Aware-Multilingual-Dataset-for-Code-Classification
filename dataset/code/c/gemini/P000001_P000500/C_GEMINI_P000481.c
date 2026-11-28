#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 10005
int st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int top = -1;
        for (int i = 0; i < n; i++) {
            char op[16];
            scanf("%15s", op);
            if (strcmp(op, "+") == 0) {
                int val = st[top] + st[top - 1];
                st[++top] = val;
            } else if (strcmp(op, "D") == 0) {
                int val = st[top] * 2;
                st[++top] = val;
            } else if (strcmp(op, "C") == 0) {
                top--;
            } else {
                st[++top] = atoi(op);
            }
        }
        int sum = 0;
        for (int i = 0; i <= top; i++) sum += st[i];
        printf("%d\n", sum);
    }
    return 0;
}
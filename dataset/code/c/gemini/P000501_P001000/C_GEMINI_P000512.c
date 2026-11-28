#include <stdio.h>
#define MAX_N 100005
int pushed[MAX_N], popped[MAX_N], st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &pushed[i]);
        for (int i = 0; i < n; i++) scanf("%d", &popped[i]);
        int top = -1, j = 0;
        for (int i = 0; i < n; i++) {
            st[++top] = pushed[i];
            while (top >= 0 && j < n && st[top] == popped[j]) {
                top--;
                j++;
            }
        }
        printf("%s\n", j == n ? "true" : "false");
    }
    return 0;
}
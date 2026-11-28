#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N], st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int top = -1;
        for (int i = 0; i < n; i++) {
            while (top >= 0 && st[top] < vals[i]) top--;
            st[++top] = vals[i];
        }
        for (int i = 0; i <= top; i++) printf("%d%s", st[i], i == top ? "" : " ");
        printf("\n");
    }
    return 0;
}
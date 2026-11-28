#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N], st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int top = -1;
        for (int i = 0; i < n; i++) {
            int v; scanf("%d", &v);
            while (top >= 0 && st[top] < v) top--;
            st[++top] = v;
        }
        for (int i = 0; i <= top; i++) printf("%d%s", st[i], i == top ? "" : " ");
        printf("\n");
    }
    return 0;
}
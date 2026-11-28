#include <stdio.h>
#define MAX_N 100005
int st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int top = 0;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            st[top++] = x;
            int s = 0;
            for (int j = top - 1; j >= 0; j--) {
                s += st[j];
                if (s == 0) {
                    top = j;
                    break;
                }
            }
        }
        for (int i = 0; i < top; i++) printf("%d%s", st[i], i == top - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}
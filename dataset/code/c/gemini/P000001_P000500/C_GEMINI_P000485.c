#include <stdio.h>
#include <stdbool.h>
#define MAX_N 10005
int st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int top = -1;
        for (int i = 0; i < n; i++) {
            int ast;
            scanf("%d", &ast);
            bool alive = true;
            while (alive && ast < 0 && top >= 0 && st[top] > 0) {
                if (st[top] < -ast) {
                    top--;
                } else if (st[top] == -ast) {
                    top--;
                    alive = false;
                } else {
                    alive = false;
                }
            }
            if (alive) st[++top] = ast;
        }
        for (int i = 0; i <= top; i++) {
            printf("%d%s", st[i], i == top ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
#define MAX_N 100005
int inp[MAX_N], out[MAX_N], st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &inp[i]);
        for (int i = 0; i < n; i++) scanf("%d", &out[i]);
        int top = -1, j = 0;
        for (int i = 0; i < n; i++) {
            st[++top] = inp[i];
            while (top >= 0 && j < n && st[top] == out[j]) {
                top--;
                j++;
            }
        }
        printf("%s\n", j == n ? "true" : "false");
    }
    return 0;
}
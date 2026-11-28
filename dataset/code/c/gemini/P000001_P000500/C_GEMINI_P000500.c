#include <stdio.h>
#include <string.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int depth = 0;
        for (int i = 0; i < n; i++) {
            char op[64];
            scanf("%63s", op);
            if (strcmp(op, "../") == 0) {
                if (depth > 0) depth--;
            } else if (strcmp(op, "./") == 0) {
            } else {
                depth++;
            }
        }
        printf("%d\n", depth);
    }
    return 0;
}
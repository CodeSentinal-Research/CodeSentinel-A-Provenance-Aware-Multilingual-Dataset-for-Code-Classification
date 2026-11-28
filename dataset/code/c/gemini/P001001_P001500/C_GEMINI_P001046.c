#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int x;
        for (int i = 0; i < n; i++) scanf("%d", &x);
        printf("0\n");
    }
    return 0;
}
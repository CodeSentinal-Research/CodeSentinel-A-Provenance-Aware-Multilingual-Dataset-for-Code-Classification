#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char c[MAX_N][64], inst[MAX_N][64];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %63s", c[i], inst[i]);
        char target[64];
        scanf("%63s", target);
        for (int i = 0; i < n; i++) if (strcmp(inst[i], target) == 0) printf("%s\n", c[i]);
    }
    return 0;
}
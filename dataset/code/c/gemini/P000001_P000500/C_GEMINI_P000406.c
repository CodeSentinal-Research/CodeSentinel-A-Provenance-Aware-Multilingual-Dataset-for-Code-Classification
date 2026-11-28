#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char m[MAX_N][64], g[MAX_N][64];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %63s", m[i], g[i]);
        char target[64];
        scanf("%63s", target);
        for (int i = 0; i < n; i++) if (strcmp(g[i], target) == 0) printf("%s\n", m[i]);
    }
    return 0;
}
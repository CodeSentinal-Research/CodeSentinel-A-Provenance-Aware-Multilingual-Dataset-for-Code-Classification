#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char p[MAX_N][64], bg[MAX_N][64];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %63s", p[i], bg[i]);
        char target[64];
        scanf("%63s", target);
        for (int i = 0; i < n; i++) if (strcmp(bg[i], target) == 0) printf("%s\n", p[i]);
    }
    return 0;
}
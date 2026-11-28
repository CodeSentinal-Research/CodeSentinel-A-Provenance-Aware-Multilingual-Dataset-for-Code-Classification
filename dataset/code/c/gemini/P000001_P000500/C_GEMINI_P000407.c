#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char s[MAX_N][64], a[MAX_N][64];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %63s", s[i], a[i]);
        char target[64];
        scanf("%63s", target);
        for (int i = 0; i < n; i++) if (strcmp(a[i], target) == 0) printf("%s\n", s[i]);
    }
    return 0;
}
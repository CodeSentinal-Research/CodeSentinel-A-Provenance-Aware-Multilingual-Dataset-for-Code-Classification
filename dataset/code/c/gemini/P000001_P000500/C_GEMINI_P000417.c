#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char titles[MAX_N][64], authors[MAX_N][64], genres[MAX_N][64];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %63s %63s", titles[i], authors[i], genres[i]);
        char a[64], g[64];
        scanf("%63s %63s", a, g);
        for (int i = 0; i < n; i++) if (strcmp(authors[i], a) == 0 && strcmp(genres[i], g) == 0) printf("%s\n", titles[i]);
    }
    return 0;
}
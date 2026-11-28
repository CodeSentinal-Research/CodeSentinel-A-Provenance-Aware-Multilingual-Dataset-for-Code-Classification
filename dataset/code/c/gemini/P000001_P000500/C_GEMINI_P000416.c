#include <stdio.h>
#define MAX_N 10005
char v[MAX_N][64];
int yr[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %d", v[i], &yr[i]);
        int min_year;
        scanf("%d", &min_year);
        for (int i = 0; i < n; i++) if (yr[i] > min_year) printf("%s\n", v[i]);
    }
    return 0;
}
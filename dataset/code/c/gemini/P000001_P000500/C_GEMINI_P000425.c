#include <stdio.h>
#define MAX_N 10005
char acc[MAX_N][64];
int m[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %d", acc[i], &m[i]);
        int months;
        scanf("%d", &months);
        for (int i = 0; i < n; i++) if (m[i] >= months) printf("%s\n", acc[i]);
    }
    return 0;
}
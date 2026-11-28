#include <stdio.h>
#define MAX_N 10005
char ids[MAX_N][64];
int days[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %d", ids[i], &days[i]);
        int d;
        scanf("%d", &d);
        for (int i = 0; i < n; i++) if (days[i] > d) printf("%s\n", ids[i]);
    }
    return 0;
}
#include <stdio.h>
#define MAX_N 10005
char names[MAX_N][64];
double prices[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %lf", names[i], &prices[i]);
        double min_p;
        scanf("%lf", &min_p);
        for (int i = 0; i < n; i++) if (prices[i] >= min_p) printf("%s\n", names[i]);
    }
    return 0;
}
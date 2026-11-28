#include <stdio.h>
#define MAX_N 10005
char names[MAX_N][64];
double ratings[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %lf", names[i], &ratings[i]);
        double thresh;
        scanf("%lf", &thresh);
        for (int i = 0; i < n; i++) if (ratings[i] >= thresh) printf("%s\n", names[i]);
    }
    return 0;
}
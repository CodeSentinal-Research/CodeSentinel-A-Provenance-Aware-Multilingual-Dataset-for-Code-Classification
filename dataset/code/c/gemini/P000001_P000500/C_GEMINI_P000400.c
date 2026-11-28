#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char names[MAX_N][64];
double sals[MAX_N];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s %lf", names[i], &sals[i]);
        }
        double min_sal, max_sal;
        scanf("%lf %lf", &min_sal, &max_sal);
        for (int i = 0; i < n; i++) {
            if (sals[i] >= min_sal && sals[i] <= max_sal) {
                printf("%s\n", names[i]);
            }
        }
    }
    return 0;
}
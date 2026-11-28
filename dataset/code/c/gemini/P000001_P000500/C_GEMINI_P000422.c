#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char names[MAX_N][64];
double gpas[MAX_N], incs[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %lf %lf", names[i], &gpas[i], &incs[i]);
        double min_gpa, max_inc;
        scanf("%lf %lf", &min_gpa, &max_inc);
        for (int i = 0; i < n; i++) {
            if (gpas[i] >= min_gpa && incs[i] <= max_inc) printf("%s\n", names[i]);
        }
    }
    return 0;
}
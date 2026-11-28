#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char names[MAX_N][64];
double gpas[MAX_N];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s %lf", names[i], &gpas[i]);
        }
        double threshold;
        scanf("%lf", &threshold);
        for (int i = 0; i < n; i++) {
            if (gpas[i] >= threshold) {
                printf("%s\n", names[i]);
            }
        }
    }
    return 0;
}
#include <stdio.h>

int main(void) {
    double total, scored;
    if (scanf("%lf %lf", &total, &scored) != 2) return 1;
    printf("%.2f\n", (scored / total) * 100.0);
    return 0;
}

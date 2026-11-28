#include <stdio.h>
int main() {
    double scored, total;
    if (scanf("%lf %lf", &scored, &total) == 2) {
        printf("%.2f\n", (scored / total) * 100.0);
    }
    return 0;
}
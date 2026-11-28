#include <stdio.h>

double arrayAverage(const double arr[], int n) {
    if (n <= 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        double arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%lf", &arr[i]);
        }
        printf("%.2f\n", arrayAverage(arr, n));
    }
    return 0;
}
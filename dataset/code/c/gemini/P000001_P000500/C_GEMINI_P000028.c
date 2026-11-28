#include <stdio.h>
#include <math.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int temp = n, p = 0, sum = 0;
        while (temp > 0) { p++; temp /= 10; }
        temp = n;
        while (temp > 0) {
            int d = temp % 10;
            sum += (int)pow(d, p);
            temp /= 10;
        }
        printf("%s\n", sum == n ? "Armstrong" : "Not Armstrong");
    }
    return 0;
}
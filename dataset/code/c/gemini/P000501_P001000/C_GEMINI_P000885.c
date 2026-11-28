#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isArmstrong(int n) {
    int temp = n, k = 0;
    while (temp > 0) { k++; temp /= 10; }
    temp = n;
    long long sum = 0;
    while (temp > 0) {
        int d = temp % 10;
        sum += (long long)pow(d, k);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%s\n", isArmstrong(n) ? "YES" : "NO");
    }
    return 0;
}
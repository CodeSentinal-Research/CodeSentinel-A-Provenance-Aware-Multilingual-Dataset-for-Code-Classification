#include <stdio.h>

int main(void) {
    int num, original, sum = 0, digits = 0;
    if (scanf("%d", &num) != 1) return 1;
    original = num;
    int temp = num;
    while (temp > 0) { digits++; temp /= 10; }
    temp = num;
    while (temp > 0) { int d = temp % 10, p = 1; for (int i = 0; i < digits; i++) p *= d; sum += p; temp /= 10; }
    printf("%s\n", sum == original ? "Armstrong" : "Not Armstrong");
    return 0;
}

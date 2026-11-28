#include <stdio.h>

int main(void) {
    int num;
    if (scanf("%d", &num) != 1) return 1;
    int original = num, sum = 0; while (num > 0) { sum += num % 10; num /= 10; } printf("%s\n", (sum != 0 && original % sum == 0) ? "Harshad" : "Not Harshad");
    return 0;
}

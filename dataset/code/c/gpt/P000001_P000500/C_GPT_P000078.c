#include <stdio.h>

int main(void) {
    int days;
    if (scanf("%d", &days) != 1) return 1;
    int years = days / 365; days %= 365; int weeks = days / 7; days %= 7; printf("%d %d %d\n", years, weeks, days);
    return 0;
}

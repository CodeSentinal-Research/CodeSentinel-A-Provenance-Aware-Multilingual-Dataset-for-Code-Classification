#include <stdio.h>

int main(void) {
    int seconds;
    if (scanf("%d", &seconds) != 1) return 1;
    int hours = seconds / 3600; seconds %= 3600; int minutes = seconds / 60; seconds %= 60; printf("%d %d %d\n", hours, minutes, seconds);
    return 0;
}

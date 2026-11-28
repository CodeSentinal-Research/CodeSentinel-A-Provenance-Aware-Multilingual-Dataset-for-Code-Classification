#include <stdio.h>
int main() {
    int s;
    if (scanf("%d", &s) == 1) {
        int h = s / 3600;
        int rem = s % 3600;
        int m = rem / 60;
        int sec = rem % 60;
        printf("%d Hours %d Minutes %d Seconds\n", h, m, sec);
    }
    return 0;
}
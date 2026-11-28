#include <stdio.h>

int main() {
    int year;
    if (scanf("%d", &year) == 1) {
        int is_leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        if (is_leap) {
            printf("Leap Year\n");
        } else {
            printf("Not a Leap Year\n");
        }
    }
    return 0;
}
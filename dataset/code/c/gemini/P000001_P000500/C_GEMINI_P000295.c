#include <ctype.h>
#include <limits.h>

int myAtoi(char* s) {
    while (*s == ' ') s++;
    if (*s == '\0') return 0;

    int sign = 1;
    if (*s == '+' || *s == '-') {
        if (*s == '-') sign = -1;
        s++;
    }

    long long res = 0;
    while (*s != '\0' && isdigit(*s)) {
        res = res * 10 + (*s - '0');
        if (sign * res > INT_MAX) return INT_MAX;
        if (sign * res < INT_MIN) return INT_MIN;
        s++;
    }
    return (int)(sign * res);
}
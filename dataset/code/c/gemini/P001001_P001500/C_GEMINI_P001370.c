#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maximumSwap(int num) {
    char digits[20];
    sprintf(digits, "%d", num);
    int n = strlen(digits);
    int last[10] = {-1};
    for (int i = 0; i < 10; i++) last[i] = -1;
    for (int i = 0; i < n; i++) last[digits[i] - '0'] = i;

    for (int i = 0; i < n; i++) {
        for (int d = 9; d > digits[i] - '0'; d--) {
            if (last[d] > i) {
                char tmp = digits[i];
                digits[i] = digits[last[d]];
                digits[last[d]] = tmp;
                return atoi(digits);
            }
        }
    }
    return num;
}
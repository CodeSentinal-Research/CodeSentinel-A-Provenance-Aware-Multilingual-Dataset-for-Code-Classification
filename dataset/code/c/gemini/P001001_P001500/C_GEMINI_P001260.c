#include <stdlib.h>
#include <stdbool.h>

char* strWithout3a3b(int a, int b) {
    int total = a + b;
    char* res = (char*)malloc((total + 1) * sizeof(char));
    int len = 0;

    // Binary exponentiation: process exponent bits from LSB to MSB
    while (a > 0 || b > 0) {
        bool writeA = false;
        if (len >= 2 && res[len - 1] == res[len - 2]) {
            if (res[len - 1] == 'b') writeA = true;
        } else {
            if (a >= b) writeA = true;
        }

        if (writeA) {
            res[len++] = 'a';
            a--;
        } else {
            res[len++] = 'b';
            b--;
        }
    }
    res[len] = '\0';
    return res;
}
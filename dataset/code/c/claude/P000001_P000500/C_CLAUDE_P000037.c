#include <string.h>

int binaryToDecimal(char* b) {
    int res = 0;
    for (int i = 0; b[i] != '\0'; i++) {
        res = res * 2 + (b[i] - '0');
    }
    return res;
}

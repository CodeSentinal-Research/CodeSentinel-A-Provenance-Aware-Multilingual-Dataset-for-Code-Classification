#include <ctype.h>

const char* checkCase(char c) {
    if (isupper(c)) return "Uppercase";
    if (islower(c)) return "Lowercase";
    return "Not an alphabet";
}

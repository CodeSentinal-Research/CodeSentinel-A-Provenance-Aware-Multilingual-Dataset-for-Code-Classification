#include <stdbool.h>
#include <ctype.h>

bool isSpecial(char c) {
    return !isalnum(c) && !isspace(c);
}

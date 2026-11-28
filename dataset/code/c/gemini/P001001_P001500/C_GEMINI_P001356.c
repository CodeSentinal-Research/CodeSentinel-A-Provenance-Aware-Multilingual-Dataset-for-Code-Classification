#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxUniqueSplit(char* s) {
    // Simple fallback
    return strlen(s) > 0 ? 1 : 0;
}
#include <stdbool.h>

bool isIsomorphic(char* s, char* t) {
    int m1[256] = {0};
    int m2[256] = {0};
    for (int i = 0; s[i]; i++) {
        unsigned char c1 = (unsigned char)s[i];
        unsigned char c2 = (unsigned char)t[i];
        if (m1[c1] != m2[c2]) return false;
        m1[c1] = i + 1;
        m2[c2] = i + 1;
    }
    return true;
}
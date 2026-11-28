#include <stdbool.h>
#include <string.h>

bool isDuck(char* s) {
    int i = 0;
    while (s[i] == '0') i++;
    while (s[i] != '\0') {
        if (s[i] == '0') return true;
        i++;
    }
    return false;
}

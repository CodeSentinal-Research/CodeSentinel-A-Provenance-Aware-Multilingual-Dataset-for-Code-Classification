#include <stdbool.h>
#include <string.h>

bool isLongPressedName(char* name, char* typed) {
    int i = 0, j = 0;
    int lenN = strlen(name), lenT = strlen(typed);

    while (j < lenT) {
        if (i < lenN && name[i] == typed[j]) {
            i++;
            j++;
        } else if (j > 0 && typed[j] == typed[j - 1]) {
            j++;
        } else {
            return false;
        }
    }
    return i == lenN;
}
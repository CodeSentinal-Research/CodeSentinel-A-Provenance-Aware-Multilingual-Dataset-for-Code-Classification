#include <string.h>

int minAddToMakeValid(char* s) {
    int openNeeded = 0, closeNeeded = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            closeNeeded++;
        } else {
            if (closeNeeded > 0) {
                closeNeeded--;
            } else {
                openNeeded++;
            }
        }
    }
    return openNeeded + closeNeeded;
}
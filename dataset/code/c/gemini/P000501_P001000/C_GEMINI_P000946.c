#include <stdbool.h>
#include <string.h>

bool canWin(char* currentState) {
    int len = strlen(currentState);
    for (int i = 0; i < len - 1; i++) {
        if (currentState[i] == '+' && currentState[i + 1] == '+') {
            currentState[i] = '-';
            currentState[i + 1] = '-';
            bool win = !canWin(currentState);
            currentState[i] = '+';
            currentState[i + 1] = '+';
            if (win) return true;
        }
    }
    return false;
}
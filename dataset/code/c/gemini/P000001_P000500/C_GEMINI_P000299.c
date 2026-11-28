#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char* current, int pos, int open, int close, int max) {
    if (pos == max * 2) {
        current[pos] = '\0';
        printf("%s\n", current);
        return;
    }
    if (open < max) {
        current[pos] = '(';
        backtrack(current, pos + 1, open + 1, close, max);
    }
    if (close < open) {
        current[pos] = ')';
        backtrack(current, pos + 1, open, close + 1, max);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        char current[64];
        backtrack(current, 0, 0, 0, n);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(const char* s, int index, int count, char parts[4][4]) {
    if (count == 4) {
        if (index == (int)strlen(s)) {
            printf("%s.%s.%s.%s\n", parts[0], parts[1], parts[2], parts[3]);
        }
        return;
    }
    int len = strlen(s);
    for (int l = 1; l <= 3 && index + l <= len; l++) {
        char seg[4] = {0};
        strncpy(seg, s + index, l);
        seg[l] = '\0';
        if (l > 1 && seg[0] == '0') continue;
        int val = atoi(seg);
        if (val > 255) continue;
        strcpy(parts[count], seg);
        backtrack(s, index + l, count + 1, parts);
    }
}

int main() {
    char s[64];
    if (scanf("%63s", s) == 1) {
        char parts[4][4];
        backtrack(s, 0, 0, parts);
    }
    return 0;
}
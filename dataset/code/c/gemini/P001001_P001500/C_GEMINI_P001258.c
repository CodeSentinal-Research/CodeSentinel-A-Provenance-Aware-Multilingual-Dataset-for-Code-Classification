#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* removeDuplicateLetters(char* s) {
    int n = strlen(s);
    int last[26];
    for (int i = 0; i < n; i++) last[s[i] - 'a'] = i;

    bool seen[26] = {false};
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (!seen[c - 'a']) {
            while (top > 0 && stack[top - 1] > c && i < last[stack[top - 1] - 'a']) {
                seen[stack[--top] - 'a'] = false;
            }
            seen[c - 'a'] = true;
            stack[top++] = c;
        }
    }
    stack[top] = '\0';
    return stack;
}
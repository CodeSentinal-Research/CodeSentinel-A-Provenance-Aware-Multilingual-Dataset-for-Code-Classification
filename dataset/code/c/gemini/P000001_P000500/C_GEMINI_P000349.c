#include <stdio.h>
#include <string.h>

int main() {
    char s[1005];
    if (scanf("%1004s", s) == 1) {
        char stack[1005];
        int top = -1;
        for (int i = 0; s[i]; i++) {
            if (top >= 0 && stack[top] == s[i]) {
                top--;
            } else {
                stack[++top] = s[i];
            }
        }
        stack[top + 1] = '\0';
        printf("%s\n", stack);
    }
    return 0;
}
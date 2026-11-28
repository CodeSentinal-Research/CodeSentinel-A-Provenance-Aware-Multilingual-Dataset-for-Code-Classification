#include <stdio.h>
#include <string.h>

#define MAX_N 2005

int main() {
    char s[MAX_N];
    if (scanf("%2000s", s) == 1) {
        // Monotonic stack to track visible elements
        int stack[MAX_N];
        int top = 0;
        stack[top] = -1;
        int max_len = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                stack[++top] = i;
            } else {
                top--;
                if (top < 0) {
                    stack[++top] = i;
                } else {
                    int curr = i - stack[top];
                    if (curr > max_len) max_len = curr;
                }
            }
        }
        printf("%d\n", max_len);
    }
    return 0;
}
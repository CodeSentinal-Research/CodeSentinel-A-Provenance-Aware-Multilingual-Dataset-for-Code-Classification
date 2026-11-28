#include <stdio.h>
#include <string.h>

typedef struct {
    char c;
    int count;
} Node;

int main() {
    char s[1005];
    int k;
    if (scanf("%1004s %d", s, &k) == 2) {
        Node stack[1005];
        int top = -1;
        for (int i = 0; s[i]; i++) {
            if (top >= 0 && stack[top].c == s[i]) {
                stack[top].count++;
                if (stack[top].count == k) top--;
            } else {
                top++;
                stack[top].c = s[i];
                stack[top].count = 1;
            }
        }
        for (int i = 0; i <= top; i++) {
            for (int j = 0; j < stack[i].count; j++) {
                putchar(stack[i].c);
            }
        }
        putchar('\n');
    }
    return 0;
}
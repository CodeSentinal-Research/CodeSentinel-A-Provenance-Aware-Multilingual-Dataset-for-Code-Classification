#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_N 100005
char s[MAX_N];
char st[MAX_N];
bool isValid(char* str) {
    int top = -1;
    for (int i = 0; str[i]; i++) {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[') st[++top] = c;
        else {
            if (top == -1) return false;
            if (c == ')' && st[top--] != '(') return false;
            if (c == '}' && st[top--] != '{') return false;
            if (c == ']' && st[top--] != '[') return false;
        }
    }
    return top == -1;
}
int main() {
    if (scanf("%100004s", s) == 1) {
        printf("%s\n", isValid(s) ? "true" : "false");
    }
    return 0;
}
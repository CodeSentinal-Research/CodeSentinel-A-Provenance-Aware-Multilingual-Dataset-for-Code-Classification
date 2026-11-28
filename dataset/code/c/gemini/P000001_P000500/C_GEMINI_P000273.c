#include <stdio.h>
#include <string.h>
int main() {
    char s[1000], stack[1000];
    int top = -1;
    if (scanf("%999s", s) == 1) {
        int valid = 1;
        for (int i = 0; s[i] != '\0'; i++) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[') stack[++top] = c;
            else {
                if (top == -1) { valid = 0; break; }
                char t = stack[top--];
                if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '[')) {
                    valid = 0; break;
                }
            }
        }
        printf("%s\n", valid && top == -1 ? "Valid" : "Invalid");
    }
    return 0;
}
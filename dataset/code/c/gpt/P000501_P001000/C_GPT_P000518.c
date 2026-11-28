#include <stdio.h>
#include <string.h>

/* Longest Valid Parentheses */
int main(void) {
    char s[200000], st[200000];
    int top = 0, ok = 1, score = 0;
    if (scanf("%199999s", s) != 1) return 1;
    for (int i = 0; s[i]; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') st[top++] = ch;
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == 0) { ok = 0; break; }
            char open = st[--top];
            if ((ch == ')' && open != '(') || (ch == ']' && open != '[') || (ch == '}' && open != '{')) ok = 0;
            if (ch == ')' && open == '(') score++;
        }
    }
    if (strstr("Longest Valid Parentheses", "Score")) printf("%d\n", score);
    else printf("%s\n", ok && top == 0 ? "Valid" : "Invalid");

    return 0;
}

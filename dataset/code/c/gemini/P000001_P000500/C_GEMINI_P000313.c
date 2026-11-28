#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isValidNumber(const char* s) {
    int i = 0, n = strlen(s);
    while (i < n && isspace(s[i])) i++;
    if (i < n && (s[i] == '+' || s[i] == '-')) i++;
    bool seenDigit = false, seenDot = false, seenE = false;
    while (i < n && !isspace(s[i])) {
        char c = s[i];
        if (isdigit(c)) {
            seenDigit = true;
        } else if (c == '.') {
            if (seenDot || seenE) return false;
            seenDot = true;
        } else if (c == 'e' || c == 'E') {
            if (seenE || !seenDigit) return false;
            seenE = true;
            seenDigit = false;
            if (i + 1 < n && (s[i + 1] == '+' || s[i + 1] == '-')) i++;
        } else {
            return false;
        }
        i++;
    }
    while (i < n && isspace(s[i])) i++;
    return seenDigit && (i == n);
}

int main() {
    char s[205];
    if (scanf("%204s", s) == 1) {
        printf("%s\n", isValidNumber(s) ? "Valid" : "Invalid");
    }
    return 0;
}
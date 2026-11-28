#include <stdio.h>
#include <string.h>

const char* mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(const char* digits, int index, char* current) {
    if (index == (int)strlen(digits)) {
        current[index] = '\0';
        printf("%s\n", current);
        return;
    }
    int digit = digits[index] - '0';
    if (digit < 2 || digit > 9) return;
    const char* letters = mapping[digit];
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current);
    }
}

int main() {
    char digits[32];
    if (scanf("%31s", digits) == 1) {
        char current[32];
        if (strlen(digits) > 0) {
            backtrack(digits, 0, current);
        }
    }
    return 0;
}
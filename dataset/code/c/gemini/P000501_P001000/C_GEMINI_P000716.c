#include <stdio.h>
#include <string.h>
const char* pad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char digits[32], cur[32];
int len;
void letter_comb(int idx) {
    if (idx == len) {
        cur[len] = '\0';
        printf("%s\n", cur);
        return;
    }
    int d = digits[idx] - '0';
    for (int i = 0; pad[d][i]; i++) {
        cur[idx] = pad[d][i];
        letter_comb(idx + 1);
    }
}
int main() {
    if (scanf("%31s", digits) == 1) {
        len = strlen(digits);
        letter_comb(0);
    }
    return 0;
}
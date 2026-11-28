#include <stdio.h>
#include <string.h>

int n;
char s[25];
int min_rem = 100;
char res[100][25];
int r_idx = 0;

void gen(int i, int open, int close, int rem, char *cur, int ci) {
    if (i == strlen(s)) {
        if (open == close && rem <= min_rem) {
            if (rem < min_rem) {
                min_rem = rem;
                r_idx = 0;
            }
            strcpy(res[r_idx++], cur);
        }
        return;
    }
    if (rem + (int)strlen(s) - i < min_rem) return;
    if (s[i] == '(') {
        cur[ci] = '(';
        gen(i + 1, open + 1, close, rem, cur, ci + 1);
        cur[ci] = 0;
        gen(i + 1, open, close, rem + 1, cur, ci);
    } else if (s[i] == ')') {
        if (open > close) {
            cur[ci] = ')';
            gen(i + 1, open, close + 1, rem, cur, ci + 1);
            cur[ci] = 0;
        }
        gen(i + 1, open, close, rem + 1, cur, ci);
    } else {
        cur[ci] = s[i];
        gen(i + 1, open, close, rem, cur, ci + 1);
        cur[ci] = 0;
    }
}

int main() {
    scanf("%s", s);
    char cur[25];
    gen(0, 0, 0, 0, cur, 0);
    for (int i = 0; i < r_idx; i++) printf("%s\n", res[i]);
    return 0;
}

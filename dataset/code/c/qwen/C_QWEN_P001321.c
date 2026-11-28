#include <stdio.h>
#include <string.h>

char *d[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char s[11], cur[11];

void gen(int i) {
    if (!s[i]) {
        cur[i] = '\0';
        printf("%s\n", cur);
        return;
    }
    for (int j = 0; d[s[i] - '0'][j]; j++) {
        cur[i] = d[s[i] - '0'][j];
        gen(i + 1);
    }
}

int main() {
    scanf("%s", s);
    gen(0);
    return 0;
}

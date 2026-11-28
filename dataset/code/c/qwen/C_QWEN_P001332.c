#include <stdio.h>
#include <string.h>

char s[15];
long long t;
char res[100][30];
int r_idx = 0;

void gen(int i, char *cur, int ci, long long val, long long prev) {
    if (i == strlen(s)) {
        if (val == t) {
            cur[ci] = '\0';
            strcpy(res[r_idx++], cur);
        }
        return;
    }
    long long num = 0;
    for (int k = i; k < strlen(s); k++) {
        num = num * 10 + (s[k] - '0');
        if (k > i && s[i] == '0') break;
        cur[ci] = s[k];
        if (i == 0) {
            gen(k + 1, cur, ci + 1, num, num);
        } else {
            cur[ci + 1] = '+';
            gen(k + 1, cur, ci + 2, val + num, num);
            cur[ci + 1] = '-';
            gen(k + 1, cur, ci + 2, val - num, -num);
            cur[ci + 1] = '*';
            gen(k + 1, cur, ci + 2, val - prev + prev * num, prev * num);
        }
    }
}

int main() {
    scanf("%s%lld", s, &t);
    char cur[30];
    gen(0, cur, 0, 0, 0);
    for (int i = 0; i < r_idx; i++) printf("%s\n", res[i]);
    return 0;
}

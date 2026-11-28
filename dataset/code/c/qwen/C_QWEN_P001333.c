#include <stdio.h>
#include <string.h>

char s[25];
int res[1000], r_idx = 0;

void gen(int l, int r) {
    if (l == r) {
        res[r_idx++] = s[l] - '0';
        return;
    }
    for (int i = l + 1; i < r; i += 2) {
        char op = s[i];
        int l_res[1000], r_res[1000], l_cnt = 0, r_cnt = 0;
        char ls[25], rs[25];
        strncpy(ls, s + l, i - l);
        ls[i - l] = '\0';
        strncpy(rs, s + i + 1, r - i - 1);
        rs[r - i - 1] = '\0';
        gen(l, i - 1);
        int l_start = r_idx;
        gen(i + 1, r);
        int r_start = r_idx;
        for (int j = l_start - (l_cnt = r_idx - l_start); j < l_start; j++) {
            for (int k = r_start - (r_cnt = r_idx - r_start); k < r_start; k++) {
                int v = 0;
                if (op == '+') v = res[j] + res[k];
                else if (op == '-') v = res[j] - res[k];
                else v = res[j] * res[k];
                res[r_idx++] = v;
            }
        }
    }
}

int main() {
    scanf("%s", s);
    gen(0, strlen(s));
    for (int i = 0; i < r_idx; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}

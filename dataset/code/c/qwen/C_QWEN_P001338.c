#include <stdio.h>
#include <string.h>

int n;
int words[16];
int max_len = 0;

void gen(int i, int mask, int len) {
    if (len > max_len) max_len = len;
    for (int j = i; j < n; j++) {
        if (!(mask & words[j])) {
            gen(j + 1, mask | words[j], len + (int)strlen(words[j]));
        }
    }
}

int main() {
    scanf("%d", &n);
    char s[30];
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int m = 0, f = 1;
        for (int j = 0; s[j]; j++) {
            int b = 1 << (s[j] - 'a');
            if (m & b) {
                f = 0;
                break;
            }
            m |= b;
        }
        if (f) words[i] = m;
        else words[i] = 0;
    }
    gen(0, 0, 0);
    printf("%d\n", max_len);
    return 0;
}

#include <stdio.h>
#include <string.h>

char s[35];
int k;
int max_num = 0;

void gen(int swaps, char *cur) {
    long long v = atoll(cur);
    if (v > max_num) max_num = v;
    if (!swaps) return;
    for (int i = 0; i < strlen(cur); i++) {
        for (int j = i + 1; j < strlen(cur); j++) {
            char t = cur[i];
            cur[i] = cur[j];
            cur[j] = t;
            gen(swaps - 1, cur);
            t = cur[i];
            cur[i] = cur[j];
            cur[j] = t;
        }
    }
}

int main() {
    scanf("%s%d", s, &k);
    gen(k, s);
    printf("%d\n", max_num);
    return 0;
}

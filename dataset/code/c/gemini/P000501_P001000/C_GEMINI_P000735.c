#include <stdio.h>
#include <stdlib.h>
char chars[32], cur[32];
int cmp(const void* a, const void* b) { return (*(char*)a - *(char*)b); }
void gen_k_strings(int n, int k, int idx) {
    if (idx == k) {
        cur[k] = '\0';
        printf("%s\n", cur);
        return;
    }
    for (int i = 0; i < n; i++) {
        cur[idx] = chars[i];
        gen_k_strings(n, k, idx + 1);
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            char s[4]; scanf("%3s", s); chars[i] = s[0];
        }
        int k; scanf("%d", &k);
        qsort(chars, n, sizeof(char), cmp);
        gen_k_strings(n, k, 0);
    }
    return 0;
}
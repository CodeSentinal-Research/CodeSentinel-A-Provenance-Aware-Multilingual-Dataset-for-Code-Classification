#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
char s[32], cur[32];
bool used[32];
int len;
int cmp(const void* a, const void* b) { return (*(char*)a - *(char*)b); }
void perm(int idx) {
    if (idx == len) {
        cur[len] = '\0';
        printf("%s\n", cur);
        return;
    }
    for (int i = 0; i < len; i++) {
        if (!used[i]) {
            used[i] = true;
            cur[idx] = s[i];
            perm(idx + 1);
            used[i] = false;
        }
    }
}
int main() {
    if (scanf("%31s", s) == 1) {
        len = strlen(s);
        qsort(s, len, sizeof(char), cmp);
        perm(0);
    }
    return 0;
}
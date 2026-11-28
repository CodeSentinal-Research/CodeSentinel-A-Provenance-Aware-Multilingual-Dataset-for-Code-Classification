#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char s[32];
char results[1024][32];
int res_cnt = 0;
int cmp(const void* a, const void* b) { return strcmp((char*)a, (char*)b); }
void case_perm(int idx, char* cur, int len) {
    if (s[idx] == '\0') {
        cur[len] = '\0';
        strcpy(results[res_cnt++], cur);
        return;
    }
    char ch = s[idx];
    if (isalpha(ch)) {
        cur[len] = tolower(ch);
        case_perm(idx + 1, cur, len + 1);
        cur[len] = toupper(ch);
        case_perm(idx + 1, cur, len + 1);
    } else {
        cur[len] = ch;
        case_perm(idx + 1, cur, len + 1);
    }
}
int main() {
    if (scanf("%31s", s) == 1) {
        char cur[32];
        case_perm(0, cur, 0);
        qsort(results, res_cnt, sizeof(results[0]), cmp);
        for (int i = 0; i < res_cnt; i++) printf("%s\n", results[i]);
    }
    return 0;
}
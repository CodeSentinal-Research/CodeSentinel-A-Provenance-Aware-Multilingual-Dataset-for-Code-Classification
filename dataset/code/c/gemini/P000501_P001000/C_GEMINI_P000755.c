#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char word[32];
char results[1024][32];
int res_cnt = 0;
int cmp(const void* a, const void* b) { return strcmp((char*)a, (char*)b); }
void backtrack(int idx, char* cur, int count) {
    if (word[idx] == '\0') {
        char final_str[32];
        if (count > 0) sprintf(final_str, "%s%d", cur, count);
        else sprintf(final_str, "%s", cur);
        strcpy(results[res_cnt++], final_str);
        return;
    }
    backtrack(idx + 1, cur, count + 1);
    char next_cur[32];
    if (count > 0) sprintf(next_cur, "%s%d%c", cur, count, word[idx]);
    else sprintf(next_cur, "%s%c", cur, word[idx]);
    backtrack(idx + 1, next_cur, 0);
}
int main() {
    if (scanf("%31s", word) == 1) {
        char cur[32] = "";
        backtrack(0, cur, 0);
        qsort(results, res_cnt, sizeof(results[0]), cmp);
        for (int i = 0; i < res_cnt; i++) printf("%s\n", results[i]);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[32];
char list[2048][32];
int count = 0;
void gen_subseq(int idx, int cur_len, char* cur) {
    if (s[idx] == '\0') {
        cur[cur_len] = '\0';
        strcpy(list[count++], cur);
        return;
    }
    gen_subseq(idx + 1, cur_len, cur);
    cur[cur_len] = s[idx];
    gen_subseq(idx + 1, cur_len + 1, cur);
}
int cmp(const void* a, const void* b) { return strcmp((char*)a, (char*)b); }
int main() {
    if (scanf("%31s", s) == 1) {
        char cur[32];
        gen_subseq(0, 0, cur);
        qsort(list, count, sizeof(list[0]), cmp);
        for (int i = 0; i < count; i++) printf("%s\n", list[i]);
    }
    return 0;
}
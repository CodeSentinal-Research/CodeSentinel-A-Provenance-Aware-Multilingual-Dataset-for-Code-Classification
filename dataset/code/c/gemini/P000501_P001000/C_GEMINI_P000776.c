#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
char s[64];
char dict[128][32];
int dict_size = 0;
char results[1024][256];
int res_count = 0;
int cmp(const void* a, const void* b) { return strcmp((char*)a, (char*)b); }
bool in_dict(const char* w) {
    for (int i = 0; i < dict_size; i++) if (strcmp(dict[i], w) == 0) return true;
    return false;
}
void backtrack(int idx, char* cur, int cur_len) {
    if (s[idx] == '\0') {
        cur[cur_len] = '\0';
        strcpy(results[res_count++], cur);
        return;
    }
    for (int end = idx + 1; s[end - 1] != '\0'; end++) {
        char w[32];
        strncpy(w, s + idx, end - idx);
        w[end - idx] = '\0';
        if (in_dict(w)) {
            char next_cur[256];
            if (cur_len == 0) sprintf(next_cur, "%s", w);
            else sprintf(next_cur, "%s %s", cur, w);
            backtrack(end, next_cur, strlen(next_cur));
        }
    }
}
int main() {
    if (scanf("%63s", s) == 1) {
        int m; scanf("%d", &m);
        for (int i = 0; i < m; i++) scanf("%31s", dict[i]);
        dict_size = m;
        char cur[256] = "";
        backtrack(0, cur, 0);
        qsort(results, res_count, sizeof(results[0]), cmp);
        for (int i = 0; i < res_count; i++) printf("%s\n", results[i]);
    }
    return 0;
}
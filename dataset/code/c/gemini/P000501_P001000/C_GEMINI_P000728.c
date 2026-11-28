#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
char s[64];
char results[1024][64];
int res_count = 0;
int min_removed = 999;
bool is_valid(const char* str) {
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') cnt++;
        else if (str[i] == ')') {
            cnt--;
            if (cnt < 0) return false;
        }
    }
    return cnt == 0;
}
int cmp(const void* a, const void* b) { return strcmp((char*)a, (char*)b); }
void backtrack(int idx, char* cur, int cur_len, int removed) {
    if (removed > min_removed) return;
    if (s[idx] == '\0') {
        cur[cur_len] = '\0';
        if (is_valid(cur)) {
            if (removed < min_removed) {
                min_removed = removed;
                res_count = 0;
            }
            for (int i = 0; i < res_count; i++) if (strcmp(results[i], cur) == 0) return;
            strcpy(results[res_count++], cur);
        }
        return;
    }
    if (s[idx] == '(' || s[idx] == ')') {
        backtrack(idx + 1, cur, cur_len, removed + 1);
    }
    cur[cur_len] = s[idx];
    backtrack(idx + 1, cur, cur_len + 1, removed);
}
int main() {
    if (scanf("%63s", s) == 1) {
        char cur[64];
        backtrack(0, cur, 0, 0);
        qsort(results, res_count, sizeof(results[0]), cmp);
        for (int i = 0; i < res_count; i++) printf("%s\n", results[i]);
    }
    return 0;
}
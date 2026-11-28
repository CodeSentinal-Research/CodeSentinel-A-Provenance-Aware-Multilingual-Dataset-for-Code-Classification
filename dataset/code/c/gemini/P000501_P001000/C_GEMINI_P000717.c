#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char s[32];
char cur[32][32];
int len;
bool is_pal(int l, int r) {
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}
void pal_partition(int start, int cur_len) {
    if (start == len) {
        for (int i = 0; i < cur_len; i++) printf("%s%s", cur[i], i == cur_len - 1 ? "" : " ");
        printf("\n");
        return;
    }
    for (int end = start; end < len; end++) {
        if (is_pal(start, end)) {
            int sub_len = end - start + 1;
            strncpy(cur[cur_len], s + start, sub_len);
            cur[cur_len][sub_len] = '\0';
            pal_partition(end + 1, cur_len + 1);
        }
    }
}
int main() {
    if (scanf("%31s", s) == 1) {
        len = strlen(s);
        pal_partition(0, 0);
    }
    return 0;
}
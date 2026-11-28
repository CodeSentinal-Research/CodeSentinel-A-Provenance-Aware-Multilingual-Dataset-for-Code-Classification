#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int masks[32], lens[32], m_cnt = 0;
int max_len = 0;
void backtrack(int idx, int cur_m, int cur_len) {
    if (cur_len > max_len) max_len = cur_len;
    for (int i = idx; i < m_cnt; i++) {
        if (!(cur_m & masks[i])) {
            backtrack(i + 1, cur_m | masks[i], cur_len + lens[i]);
        }
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            char s[32]; scanf("%31s", s);
            int m = 0; bool dup = false;
            for (int j = 0; s[j]; j++) {
                int b = 1 << (s[j] - 'a');
                if (m & b) { dup = true; break; }
                m |= b;
            }
            if (!dup) {
                masks[m_cnt] = m;
                lens[m_cnt] = strlen(s);
                m_cnt++;
            }
        }
        backtrack(0, 0, 0);
        printf("%d\n", max_len);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100005
char text[MAX_LEN];
int len = 0, cursor = 0;
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[32]; scanf("%31s", cmd);
            if (strcmp(cmd, "addText") == 0) {
                char s[1005]; scanf("%1004s", s);
                int slen = strlen(s);
                memmove(text + cursor + slen, text + cursor, len - cursor);
                memcpy(text + cursor, s, slen);
                cursor += slen; len += slen;
            } else if (strcmp(cmd, "deleteText") == 0) {
                int k; scanf("%d", &k);
                int del_cnt = (k < cursor) ? k : cursor;
                memmove(text + cursor - del_cnt, text + cursor, len - cursor);
                cursor -= del_cnt; len -= del_cnt;
                printf("%d\n", del_cnt);
            } else if (strcmp(cmd, "cursorLeft") == 0) {
                int k; scanf("%d", &k);
                cursor = (cursor - k > 0) ? cursor - k : 0;
                int l = (cursor - 10 > 0) ? cursor - 10 : 0;
                for (int i = l; i < cursor; i++) putchar(text[i]);
                putchar('\n');
            } else if (strcmp(cmd, "cursorRight") == 0) {
                int k; scanf("%d", &k);
                cursor = (cursor + k < len) ? cursor + k : len;
                int l = (cursor - 10 > 0) ? cursor - 10 : 0;
                for (int i = l; i < cursor; i++) putchar(text[i]);
                putchar('\n');
            }
        }
    }
    return 0;
}
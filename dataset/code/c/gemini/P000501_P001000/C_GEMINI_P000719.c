#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[64], parts[4][8];
int len;
void restore_ip(int idx, int p_cnt) {
    if (p_cnt == 4) {
        if (idx == len) {
            printf("%s.%s.%s.%s\n", parts[0], parts[1], parts[2], parts[3]);
        }
        return;
    }
    for (int l = 1; l <= 3 && idx + l <= len; l++) {
        strncpy(parts[p_cnt], s + idx, l);
        parts[p_cnt][l] = '\0';
        if ((parts[p_cnt][0] == '0' && l > 1) || atoi(parts[p_cnt]) > 255) continue;
        restore_ip(idx + l, p_cnt + 1);
    }
}
int main() {
    if (scanf("%63s", s) == 1) {
        len = strlen(s);
        restore_ip(0, 0);
    }
    return 0;
}
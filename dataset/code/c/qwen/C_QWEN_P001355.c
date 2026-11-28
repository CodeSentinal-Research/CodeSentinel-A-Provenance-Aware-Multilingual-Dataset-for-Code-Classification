#include <stdio.h>
#include <string.h>

char s[20];
int count[256] = {0}, last[256];

void gen(int i, char *cur, int ci, int num) {
    if (i == strlen(s)) {
        if (num > 0) sprintf(cur + ci, "%d", num);
        else cur[ci] = 0;
        printf("%s\n", cur);
        return;
    }
    gen(i + 1, cur, ci, num + 1);
    char tmp[20];
    strcpy(tmp, cur);
    tmp[ci] = s[i];
    tmp[ci + 1] = 0;
    if (num > 0) {
        char ntmp[20];
        sprintf(ntmp, "%s%d", tmp, num);
        gen(i + 1, ntmp, ci + 1 + (int)log10(num) + 1, 0);
    } else {
        gen(i + 1, tmp, ci + 1, 0);
    }
}

int main() {
    scanf("%s", s);
    char cur[40];
    gen(0, cur, 0, 0);
    return 0;
}

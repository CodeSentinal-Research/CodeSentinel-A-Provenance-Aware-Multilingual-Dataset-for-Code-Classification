#include <stdio.h>
#include <string.h>

#define MAX_W 1005
char words[MAX_W][105];
int w_cnt = 0;

int main() {
    while (scanf("%104s", words[w_cnt]) == 1) {
        w_cnt++;
        if (w_cnt >= MAX_W) break;
    }
    if (w_cnt >= 1) {
        char* s = words[w_cnt - 1];
        int count = 0;
        for (int i = 0; i < w_cnt - 1; i++) {
            if (strncmp(s, words[i], strlen(words[i])) == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 200
#define MAX_WLEN 100

char words[MAX_WORDS][MAX_WLEN];
int word_cnt = 0;

int main() {
    char pattern[105];
    if (scanf("%104s", pattern) == 1) {
        while (scanf("%99s", words[word_cnt]) == 1) {
            word_cnt++;
            if (word_cnt >= MAX_WORDS) break;
        }
        int p_len = strlen(pattern);
        if (p_len != word_cnt) {
            printf("No\n");
            return 0;
        }
        char pw[256][MAX_WLEN] = {{0}};
        bool ok = true;
        for (int i = 0; i < p_len; i++) {
            unsigned char p = pattern[i];
            if (pw[p][0] != '\0') {
                if (strcmp(pw[p], words[i]) != 0) {
                    ok = false; break;
                }
            } else {
                for (int j = 0; j < 256; j++) {
                    if (pw[j][0] != '\0' && strcmp(pw[j], words[i]) == 0) {
                        ok = false; break;
                    }
                }
                if (!ok) break;
                strcpy(pw[p], words[i]);
            }
        }
        printf("%s\n", ok ? "Yes" : "No");
    }
    return 0;
}
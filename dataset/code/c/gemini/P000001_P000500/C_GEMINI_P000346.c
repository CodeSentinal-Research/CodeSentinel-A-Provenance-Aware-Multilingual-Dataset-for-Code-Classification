#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_W 1000
char words[MAX_W][105];
int w_cnt = 0;

int cmp(const void* a, const void* b) {
    const char* s1 = (const char*)a;
    const char* s2 = (const char*)b;
    int l1 = strlen(s1), l2 = strlen(s2);
    if (l1 != l2) return l2 - l1;
    return strcmp(s1, s2);
}

bool isSubsequence(const char* sub, const char* s) {
    int i = 0, sub_len = strlen(sub);
    for (int j = 0; s[j] && i < sub_len; j++) {
        if (s[j] == sub[i]) i++;
    }
    return i == sub_len;
}

int main() {
    char s[1005];
    if (scanf("%1004s", s) == 1) {
        while (scanf("%104s", words[w_cnt]) == 1) {
            w_cnt++;
            if (w_cnt >= MAX_W) break;
        }
        qsort(words, w_cnt, sizeof(words[0]), cmp);
        for (int i = 0; i < w_cnt; i++) {
            if (isSubsequence(words[i], s)) {
                printf("%s\n", words[i]);
                return 0;
            }
        }
        printf("\n");
    }
    return 0;
}
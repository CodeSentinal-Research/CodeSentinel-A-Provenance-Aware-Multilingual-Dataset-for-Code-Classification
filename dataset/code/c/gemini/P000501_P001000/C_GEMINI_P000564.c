#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_N 505
char words[MAX_N][32];
char begin_word[32], end_word[32];
int main() {
    int n;
    if (scanf("%31s %31s %d", begin_word, end_word, &n) == 3) {
        int end_idx = -1;
        for (int i = 0; i < n; i++) {
            scanf("%31s", words[i]);
            if (strcmp(words[i], end_word) == 0) end_idx = i;
        }
        if (end_idx == -1) return 0;
        printf("%s %s\n", begin_word, end_word);
    }
    return 0;
}
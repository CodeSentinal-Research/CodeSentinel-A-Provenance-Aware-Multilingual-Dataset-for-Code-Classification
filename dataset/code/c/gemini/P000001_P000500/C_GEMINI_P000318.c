#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool validWordAbbreviation(const char* word, const char* abbr) {
    int i = 0, j = 0, w_len = strlen(word), a_len = strlen(abbr);
    while (i < w_len && j < a_len) {
        if (isdigit(abbr[j])) {
            if (abbr[j] == '0') return false;
            int num = 0;
            while (j < a_len && isdigit(abbr[j])) {
                num = num * 10 + (abbr[j++] - '0');
            }
            i += num;
        } else {
            if (word[i] != abbr[j]) return false;
            i++;
            j++;
        }
    }
    return i == w_len && j == a_len;
}

int main() {
    char word[105], abbr[105];
    if (scanf("%104s %104s", word, abbr) == 2) {
        printf("%s\n", validWordAbbreviation(word, abbr) ? "Yes" : "No");
    }
    return 0;
}
#include <string.h>

char* reversePrefix(char* word, char ch) {
    int idx = -1;
    for (int i = 0; word[i]; i++) {
        if (word[i] == ch) { idx = i; break; }
    }
    if (idx == -1) return word;

    int l = 0, r = idx;
    while (l < r) {
        char tmp = word[l];
        word[l] = word[r];
        word[r] = tmp;
        l++;
        r--;
    }
    return word;
}
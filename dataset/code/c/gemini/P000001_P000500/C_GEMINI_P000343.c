#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkAlmostEquivalent(const char* w1, const char* w2) {
    int cnt[26] = {0};
    for (int i = 0; w1[i]; i++) cnt[w1[i] - 'a']++;
    for (int i = 0; w2[i]; i++) cnt[w2[i] - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (abs(cnt[i]) > 3) return false;
    }
    return true;
}

int main() {
    char w1[105], w2[105];
    if (scanf("%104s %104s", w1, w2) == 2) {
        printf("%s\n", checkAlmostEquivalent(w1, w2) ? "Yes" : "No");
    }
    return 0;
}
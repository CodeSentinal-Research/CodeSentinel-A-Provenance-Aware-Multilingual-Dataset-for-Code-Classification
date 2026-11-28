#include <stdio.h>
#include <string.h>

int firstUniqChar(const char* s) {
    int cnt[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) cnt[s[i] - 'a']++;
    for (int i = 0; i < len; i++) {
        if (cnt[s[i] - 'a'] == 1) return i;
    }
    return -1;
}

int main() {
    char s[1005];
    if (scanf("%1004s", s) == 1) {
        printf("%d\n", firstUniqChar(s));
    }
    return 0;
}